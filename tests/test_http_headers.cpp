#include <gtest/gtest.h>
#include <http_headers.hpp>
#include <iostream>

TEST(FIRST_SUITE, FIRST_TEST) {
   std::wcout << L"Test is running" << std::endl;
   http::HttpHeaders{};
   assert(true);
}