#include <iostream>
#include <vector>

/**
 * @brief This library's purspose is to provide the programmer with additional potentially useful functions that can be used on strings.
 * You are free to suggest any improvement in the "Discussions" page or in the "Issues" page, provided that you also give a working example
 * to explain how you are solving the problem!
 */

/**
 * @brief This function splits the given string into a vector of strings using the given delimiter.
 * 
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
 * @warning As of C++20, there are standard functions that allow two strings to be joined. This hand-made version is therefore suitable for all C++ standard versions prior to C++20.
 */
void join(std::string& v1, const std::string& v2) noexcept {
    for(const auto& i: v2) {
        v1.push_back(i);
    }
}
