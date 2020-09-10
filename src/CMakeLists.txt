cmake_minimum_required(VERSION 3.13.2)
project(SimpleGetRequest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(HEADERS http_headers)
set(SRC_LIST main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_sources(${PROJECT_NAME} PRIVATE http_headers/http_headers.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADERS})