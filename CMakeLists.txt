cmake_minimum_required(VERSION 3.23)
project(wallet)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

option(TESTING "Build test" OFF)
option(SERVER "Build server" OFF)

include_directories(include)

add_subdirectory(deps)

add_subdirectory(core)
include_directories(
        ${PROJECT_SOURCE_DIR}/core
        ${PROJECT_SOURCE_DIR}/include
)

if (TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
