#pragma once

#include <string>

#include <boost/asio.hpp>
#include <jsonrpccxx/server.hpp>

/**
 * JSON-BYTES:
 *
 *      Json-request-RPC:
 *          {
 *              "jsonrpc": "2.0": STRING,
 *              "method": "${method_name}": STRING,
 *              "params": {${}: ANY}: ARRAY,
 *              "id": ${NUMBER_ID}: INT
 *          }
 *
 *      Json-response-RPC:
 *          {
 *              "jsonrpc": "2.0": STRING,
 *              "result": ${}: ANY,
 *              "id": ${NUMBER_ID}: INT
 *          }
 */

namespace tcp {
  class Server {
   public:
    Server(std::string_view const &address, std::string_view const &port);

    void run();

   private:
    void do_accept();

    void do_await_stop();

    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
  };
}  // namespace tcp
