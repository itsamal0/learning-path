#pragma once
#include <string>
#include <vector>

namespace helperFunctions
{
    std::string readString(std::string message);
    std::string upperAllString(std::string str);
    std::string lowerAllString(std::string str);
    std::vector<std::string> splitString(std::string str, std::string delimiter);
    std::string trimLeft(std::string str);
    std::string trimRight(std::string str);
    std::string trim(std::string str);
    std::string joinString(const std::vector<std::string>& vString, std::string delimiter);
    char readLetter(std::string message);
    char inverLetterCase(char c);
}
