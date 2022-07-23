#ifndef STRINGEXT_H
#define STRINGEXT_H

#include <iostream>
#include <vector>
#include <algorithm>

#if __cplusplus >= 201703L
#include <string_view>
std::vector<std::string_view> split(const std::string_view& str, const std::string_view& delim) noexcept;
#else //__cplusplus < 201703L
std::vector<std::string> split(const std::string& str, const std::string& delim) noexcept
#endif

void join(std::string& v1, const std::string& v2) noexcept;

#endif
