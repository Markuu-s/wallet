cmake_minimum_required(VERSION 3.23)
project(wallet)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

option(TESTING "Build test" OFF)

include_directories(include)

add_subdirectory(core)

if (TESTING)

endif()
