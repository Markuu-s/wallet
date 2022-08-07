#pragma once

#include <string>

#include <boost/asio.hpp>

namespace tcp {
    class Server {
    public:
        Server(std::string_view const &address,
               std::string_view const &port);

        void run();

    private:
        void do_accept();

        void do_await_stop();

        boost::asio::io_context io_context_;
        boost::asio::ip::tcp::acceptor acceptor_;

    };
}
