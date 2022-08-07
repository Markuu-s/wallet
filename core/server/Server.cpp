#include "Server.hpp"

// Reference:
// https://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/tutorial/tutdaytime3.html
// https://www.boost.org/doc/libs/1_78_0/doc/html/boost_asio/example/cpp11/http/server/server.hpp
// https://www.boost.org/doc/libs/1_78_0/doc/html/boost_asio/example/cpp11/http/server/server.cpp

namespace tcp {
  using TCP = boost::asio::ip::tcp;

  Server::Server(std::string_view const &address, std::string_view const &port)
      : io_context_(1),
        acceptor_(io_context_, TCP::endpoint(TCP::endpoint(TCP::v4(), 8080))) {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    boost::asio::ip::tcp::endpoint endpoint =
        *resolver.resolve(address, port).begin();

    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();

    do_accept();
  }

  void Server::do_await_stop() {}

  void Server::do_accept() {
    acceptor_.async_accept([this](boost::system::error_code ec,
                                  boost::asio::ip::tcp::socket socket) {
      if (!acceptor_.is_open()) {
        return;
      }

      if (!ec) {
      }

      do_accept();
    });
  }
}  // namespace tcp