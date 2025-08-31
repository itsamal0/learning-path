#pragma once
#include <string>
#include <vector>

namespace helperFunctions
{
    std::string readString(std::string message);
    std::string upperAllString(std::string str);
    std::string lowerAllString(std::string str);
    std::vector<std::string> splitString(std::string str, std::string delimiter);
    char readLetter(std::string message);
    char inverLetterCase(char c);
}
