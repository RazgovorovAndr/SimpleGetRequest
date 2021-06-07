project(MainLibrary)

Message(${PROJECT_NAME})
Message(${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC)
target_link_libraries(${PROJECT_NAME} PRIVATE curl)

target_sources(
    ${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/implementation/http_headers.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/implementation/http_client.cpp"
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    )