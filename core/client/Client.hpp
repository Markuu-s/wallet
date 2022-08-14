#pragma once
#include <string>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <jsonrpccxx/client.hpp>

namespace core::client {
  class Client {
   public:
    Client() = delete;
    static void connect(std::string_view const &address, uint8_t const &port);
    static std::string_view send_receive(std::string_view const &method, ... /*params*/);

   private:
    static boost::asio::io_service io_service_;
    static boost::asio::ip::tcp::socket *socket_; // TODO make smart pointer
    static jsonrpccxx::IClientConnector client_connector_;
  };
}  // namespace core::client
