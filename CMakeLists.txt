cmake_minimum_required(VERSION 3.23)
project(wallet)

message("System name: ${CMAKE_SYSTEM_NAME}")

message("Build dir: ${CMAKE_BINARY_DIR}")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# cmake_find_package()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

option(TESTING "Build test" OFF)

include_directories(include)

add_subdirectory(deps)

add_subdirectory(core)
include_directories(
        ${PROJECT_SOURCE_DIR}/libcore
        ${PROJECT_SOURCE_DIR}/include
)

if (TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
