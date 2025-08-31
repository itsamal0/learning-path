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

string helperFunctions::reverseWordsInString(string str) { 
    vector<string> vString;
    string str2 = "";
    vString = helperFunctions::splitString(str, " ");

    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin()) {
        --iter;
        str2 += *iter + " ";
    }

    str2 = str2.substr(0, str2.length() - 1);
    return str2;
}


string helperFunctions::replace(string str, string targetWord, string replacementWord, bool matchCase)
{
    vector<string> vString;
    vString = helperFunctions::splitString(str, " ");

    for (string& s : vString) {
        if (matchCase) {
            if (s == targetWord) {
                s = replacementWord;
            }
        } else {
            if (helperFunctions::lowerAllString(s) == helperFunctions::lowerAllString(targetWord)) {
                s = replacementWord;
            }
        }
    }

    return helperFunctions::joinString(vString, " ");
}

string helperFunctions::removePunctuationsFromString(string str) {
    string str2 = "";
    for (int i = 0; i < str.length(); i++) {
        if (!ispunct(str[i])) {
            str2 += str[i];
        }
    }
    return str2;
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

int helperFunctions::readPositiveNumber(string message) {
    int num = 0;
    bool validInput = false;

    do {
        cout << message;
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
        } else if (num <= 0) {
            cout << "Number must be positive!\n";
        } else {
            validInput = true;
        }

    } while (!validInput);

    return num;
}