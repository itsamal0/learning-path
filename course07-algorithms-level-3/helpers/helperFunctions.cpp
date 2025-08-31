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

vector<string> helperFunctions::splitString(string str, string delimiter) {
    vector<string> vString;
    short pos = 0;
    string word;

    while ((pos = str.find(delimiter)) != string::npos) {
        word = str.substr(0, pos);
        if (!word.empty()) {
            vString.push_back(word);
        }
        str.erase(0, pos + delimiter.length());
    }

    if (!str.empty()) {
        vString.push_back(str);
    }

    return vString;
}

string helperFunctions::trimLeft(string str) {
    while (!str.empty() && str[0] == ' ') {
        str.erase(0, 1);
    }
    return str;
}

string helperFunctions::trimRight(string str) {
    while (!str.empty() && str[str.length() - 1] == ' ') {
        str.erase(str.length() - 1, 1);
    }
    return str;
}

string helperFunctions::trim(string str) {
    return trimLeft(trimRight(str));
}

string helperFunctions::joinString(const vector<string>& vString, string delimiter) {
    if (vString.empty()) return "";

    string str = "";
    for (const string& word : vString) {
        str += word + delimiter;
    }

    return str.substr(0, str.length() - delimiter.length());
}

string helperFunctions::joinString(string strArr[], short arrSize, string delimiter) {
    string str = "";
    for (int i = 0; i < arrSize; i++) {
        str += strArr[i] + delimiter;
    }
    return str.substr(0, str.length() - delimiter.length());
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