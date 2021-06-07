#include <fstream>
#include <http_client.hpp>
#include <http_headers.hpp>
#include <iostream>

int main(int /*argc*/, char ** /*argv*/) {
   std::cout << "Hello, world!" << std::endl;
   http::HttpHeaders headers{};
   http::HttpClient client;
   std::ofstream out("/home/andrei/Downloads/2/test.html");
   client.SendGetRequest("https://example.com", out);
   std::cout << "omg" << std::endl;
   out.close();
   return 0;
}
