#pragma once
#include <string>
using namespace std;

namespace io_utils {
    string readString(const string& message);
    int readPositiveNumber(const string& message);
    char readLetter(const string& message);
}