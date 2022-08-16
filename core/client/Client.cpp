#include "Client.hpp"

#include <boost/asio.hpp>

namespace core::client {
  using boost::asio::ip::tcp;

  void Client::connect(std::string_view const &address, int const &port) {
    socket_ = new boost::asio::ip::tcp::socket(io_service_);

    socket_->connect(tcp::endpoint(
        boost::asio::ip::address::from_string(address.data()), port));
  }
}  // namespace core::client
