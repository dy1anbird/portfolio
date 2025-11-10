#ifndef SPLIT_H
#define SPLIT_H
#include <sstream>
#include <string>
#include <vector>
inline
std::vector<std::string> split(const std::string& s, char split_char) {
    std::istringstream iss(s);
    std::string buffer;
    std::vector<std::string> result;
    while (getline(iss, buffer, split_char))
        result.push_back(buffer);
    return result;
}
#endif
