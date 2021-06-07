#include <curl/curl.h>
#include <http_headers.hpp>
#include <iostream>
#include <string>

namespace http {

HttpHeaders::HttpHeaders(
    const std::unordered_map<std::wstring, std::wstring> &headers)
    : _headers(headers) {}

void HttpHeaders::SetHeader(const std::wstring &header, const std::wstring &value) {
   _headers[header] = value;
}

const std::wstring HttpHeaders::GetHeader(const std::wstring &header) noexcept {
   try {
      return _headers[header];
   } catch (const std::out_of_range & /*e*/) {
      return std::wstring{};
   } catch (...) {
      // TODO: replace with log class
      std::wcout << L"ERROR" << std::endl;
      ;
      return std::wstring{};
   }
}

void HttpHeaders::DelHeader(const std::wstring &header) noexcept {
   auto it = _headers.find(header);
   if (it != _headers.end())
      _headers.erase(it);
}

} // namespace http