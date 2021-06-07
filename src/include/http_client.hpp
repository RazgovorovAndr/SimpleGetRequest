#pragma once
#include <curl/curl.h>
#include <iostream>
#include <memory>

namespace http {

class HttpClient {
 public:
   HttpClient();
   ~HttpClient();
   int SendGetRequest(const std::string &url, std::ostream &response);

 private:
   CURL *curl;
};

} // namespace http