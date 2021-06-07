#include <curl/curl.h>
#include <http_client.hpp>
#include <string_view>

namespace http {

// функция, вызываемая cURL для записи полученых данных
std::string curlBuffer;

size_t write_callback(char *data, size_t size, size_t nmemb, void *userdata) {
   std::ostream *response = static_cast<std::ostream *>(userdata);
   if (!response)
      return 0;
   response->write(data, size * nmemb);
   return size * nmemb;
}

HttpClient::HttpClient() { curl = curl_easy_init(); }

HttpClient::~HttpClient() {
   if (curl)
      curl_easy_cleanup(curl);
}

int HttpClient::SendGetRequest(const std::string &url, std::ostream &response) {

   if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url.data());
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1);
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

      // буфер для сохранения текстовых ошибок
      char curlErrorBuffer[CURL_ERROR_SIZE];
      curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curlErrorBuffer);
      // функция, вызываемая cURL для записи полученых данных
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

      // выполнить запрос
      CURLcode curlResult = curl_easy_perform(curl);

      if (curlResult != CURLE_OK) {
         std::cout << "Ошибка(" << curlResult << "): " << curlErrorBuffer
                   << std::endl;
         return (-1);
      }
   }
   return 0;
}

} // namespace http