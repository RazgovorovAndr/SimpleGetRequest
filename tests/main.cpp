#include <gtest/gtest.h>
#include <iostream>

int main(int /*argc*/, char ** /*argv*/) {
   std::cout << "Hello, test!" << std::endl;
   testing::InitGoogleTest();
   return RUN_ALL_TESTS();
}