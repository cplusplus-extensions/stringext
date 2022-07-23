#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief This library's purpose is to provide the programmer with additional potentially useful functions that can be used on strings.
 * You are free to suggest any improvement in the "Discussions" page or in the "Issues" page, provided that you also give a working example
 * to explain how you are solving the problem!
 */

#if __cplusplus >= 201703L
#include <string_view>

/**
 * @brief This function joins two strings into one resulting string, appending every character in the second string to the end of the first string.
 * 
 * @param v1 The first string
 * @param v2 The second string
 * 
 * @warning As of C++20, there are standard functions that allow two strings to be joined. This hand-made version is therefore suitable for all C++ standard versions prior to C++20 that implement std::for_each.
 */
void join(std::string& v1, const std::string& v2) noexcept {
    std::for_each(v1.begin(), v1.end(), [&v1](char i) {
        v1.push_back(i);
    });
}

/**
 * @brief This function splits the given string into a vector of strings using the given delimiter.
 * 
 * @warning This function uses the STL algorithm "std::for_each" and <string_view>, therefore it is suitable for all C++ versions since C++17.
 * @param str The string to split
 * @param delim The delimiter used to split the string
 * @return std::vector<std::string> The resulting vector as described above.
 */
std::vector<std::string> split(const std::string& str, const std::string& delim) noexcept {
    std::string str1;
    std::vector<std::string> v;
    std::for_each(str.begin(), str.end(), [&v, &str1, delim](char it) {
        if(delim.find(it) == std::string::npos) {
            str1.push_back(it);
        } else {
            v.push_back(str1);
            str1.clear();
        }
    });
    v.push_back(str1);

    return v;
}

#else

/**
 * @brief This function splits the given string into a vector of strings using the given delimiter.
 * 
 * @warning This function uses the STL algorithm "std::for_each" and <string_view>, therefore it is suitable for all C++ versions since C++17.
 * @param str The string to split
 * @param delim The delimiter used to split the string
 * @return std::vector<std::string> The resulting vector as described above.
 */
std::vector<std::string> split(const std::string& str, const std::string& delim) noexcept {
    std::string str1;
    std::vector<std::string> v;
    for(const char& it : str) {
        if(delim.find(it) == std::string::npos) {
            str1 += it;
        } else {
            v.push_back(str1);
            str1 = "";
        }
    }
    v.push_back(str1);

    return v;
}

/**
 * @brief This function joins two strings into one resulting string, appending every character in the second string to the end of the first string.
 * 
 * @param v1 The first string
 * @param v2 The second string
 * 
 * @warning As of C++17, std::for_each has been introduced. This hand-made version is therefore suitable for all C++ standard versions prior to C++17.
 */
void join(std::string& v1, const std::string& v2) noexcept {
    for(const auto& i: v2) {
        v1.push_back(i);
    }
}

#endif
