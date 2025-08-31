#include <iostream>
#include <string>
using namespace std;

/*
==================================================
   Problem: Write a program to lowercase the first 
            letter of each word in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Read a full string from the user
string readAString() {
    string str = "";
    cout << "Please enter your string ?" << endl;
    getline(cin, str);
    return str;
}

// Convert the first letter of each word to lowercase
string lowerFirstLetterOfEachWord(string str) {
    short strLength = str.length();
    bool isFirstLetter = true;

    for (int i = 0; i < strLength; i++) {
        if (str[i] != ' ' && isFirstLetter) {
            str[i] = tolower(str[i]);
        }
        isFirstLetter = (str[i] == ' ' ? true : false);
    }

    return str;
}

int main() {
    string str = readAString();
    cout << "\nString after conversion:\n";
    cout << lowerFirstLetterOfEachWord(str);
    return 0;
}