cmake_minimum_required(VERSION 3.23)
project(wallet)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(core)
include_directories(include)

add_library(wallet core/wallet.cpp)
