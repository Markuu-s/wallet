#include "Client.hpp"

#include <boost/asio.hpp>
#include <jsonrpccxx/client.hpp>

namespace core::client {
  using boost::asio::ip::tcp;

  void Client::connect(std::string_view const &address, uint8_t const &port) {
    socket_ = new boost::asio::ip::tcp::socket(io_service_);

    socket_->connect(tcp::endpoint(
        boost::asio::ip::address::from_string(address.data()), port));
  }

  std::string_view Client::send_receive(std::string_view const &method,
                                        ...  /*params*/) {
    jsonrpccxx::JsonRpcClient client(client_connector_,
                                     jsonrpccxx::version::v2);

    boost::system::error_code error_code;
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
