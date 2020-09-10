#include <iostream>
#include <http_headers.hpp>

int main(int argc, char **argv)
{
    std::cout << "Hello, world!"<< std::endl;;
    HttpHeaders headers{};
    headers.SetHeader(L"sid", L"4214-532-fde");
    std::wcout << headers.GetHeader(L"sid") << std::endl;
    std::wcout << headers.GetHeader(L"keep-alive") << std::endl;
    return 0;
}
