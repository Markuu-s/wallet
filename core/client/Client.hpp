#pragma once
#include <string>

#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

namespace core::client {
  class Client {
   public:
    Client() = delete;
    static void connect(std::string_view const &address, uint8_t const &port);
    template <typename... Args>
    static std::string_view sendReceive(std::string_view const &method,
                                        Args... args);

   private:
    static boost::asio::io_service io_service_;
    static boost::asio::ip::tcp::socket *socket_;  // TODO make smart pointer
  };

  template <typename T, typename... Targs>
  void addParams(nlohmann::json &json, T value, Targs... args) {
    json["params"].push_back(value);
    if (sizeof...(args) == 0) return;
    add_params(json, args...);
  }

  template <typename... Args>
  std::string_view Client::sendReceive(std::string_view const &method,
                                       Args... args) {
    boost::system::error_code error_code;

    nlohmann::json json = {{"method", method}, {"params", {}}};
    addParams(json, args...);

    boost::asio::write(*socket_, boost::asio::buffer("TODO MSG"), error_code);

    if (error_code) {
      // TODO error
    }

    boost::asio::streambuf receive_buffer;
    boost::asio::read(
        *socket_, receive_buffer, boost::asio::transfer_all(), error_code);

    if (error_code && error_code != boost::asio::error::eof) {
      // TODO error
    }

    return boost::asio::buffer_cast<const char *>(receive_buffer.data());
  }
}  // namespace core::client
