#include <gtest/gtest.h>
#include <iostream>

#include "client/Client.hpp"

class Mock {};

TEST(Mock, HelloWorld) {
  std::cout << "Hello world";
  core::client::Client::sendReceive("Test1", "params1", "params2", 1, 2);
}
