#pragma once
#include <unordered_map>

namespace http {

class HttpHeaders {
 public:
   HttpHeaders() = default;
   explicit HttpHeaders(
       const std::unordered_map<std::wstring, std::wstring> &headers);
   ~HttpHeaders() = default;

   void SetHeader(const std::wstring &header, const std::wstring &value);
   const std::wstring GetHeader(const std::wstring &header) noexcept;
   void DelHeader(const std::wstring &header) noexcept;

 private:
   std::unordered_map<std::wstring, std::wstring> _headers;
};

} // namespace http