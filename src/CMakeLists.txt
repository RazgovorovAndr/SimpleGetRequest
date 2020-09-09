cmake_minimum_required(VERSION 3.13.2)
project(SimpleGetRequest)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

#include_directories("file_reader" "file_writer" "app")
set(SRC_LIST main.cpp)
add_executable(${PROJECT_NAME} ${SRC_LIST})
