#include <iostream>
#include <string>
using namespace std;

/*
==================================================
   Problem: Write a program to print the first letter of each word in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Function to read a full string from the user
string readAString() {
    string str = "";
    cout << "Please enter your string ?" << endl;
    getline(cin, str);

    return str;
}

// Function to print the first letter of each word
void printFirstLetterOfEachWord(string str) {
    short strLength = str.length();

    if (strLength == 0) return;

    if (str[0] != ' ')
        cout << str[0] << endl;

    for (int i = 1; i < strLength; i++) {
        if (str[i] == ' ' && i + 1 < strLength && str[i + 1] != ' ') {
            cout << str[i + 1] << endl;
        }
    }
}

int main() {
    printFirstLetterOfEachWord(readAString());
    return 0;
}