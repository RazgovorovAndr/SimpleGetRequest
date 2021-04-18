#include <iostream>
#include <gtest/gtest.h>
#include <http_headers.hpp>

TEST(FIRST_SUITE, FIRST_TEST)
{
   std::wcout << L"Test is running" << std::endl;
   HttpHeaders{};
   assert(true); 
}