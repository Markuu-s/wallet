#include <gtest/gtest.h>
#include <iostream>

class Mock {};

TEST(Mock, HelloWorld) {
  std::cout << "Hello world";
}
