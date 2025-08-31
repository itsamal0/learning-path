#include "helperFunctions.h"
#include <cctype>
#include <iostream>
using namespace std;

string helperFunctions::readString(string message) {
    string str = "";
    cout << message << endl;
    getline(cin, str);
    return str;
}

string helperFunctions::upperAllString(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

string helperFunctions::lowerAllString(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

char helperFunctions::readLetter(string message) {
    char c = ' ';
    cout << message << endl;
    cin >> c;
    return c;
}

char helperFunctions::inverLetterCase(char c) {
    return isupper(c) ? tolower(c) : toupper(c);
}