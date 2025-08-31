#include <iostream>
#include <string>
using namespace std;

/*
==================================================
   Problem: Write a program to convert a string  
            to uppercase and to lowercase.
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

// Convert the entire string to uppercase
string upperAllString(string str) {
    short strLength = str.length();

    for (int i = 0; i < strLength; i++) {
        if (str[i]) {
            str[i] = toupper(str[i]);
        }
    }

    return str;
}

// Convert the entire string to lowercase
string lowerAllString(string str) {
    short strLength = str.length();

    for (int i = 0; i < strLength; i++) {
        if (str[i]) {
            str[i] = tolower(str[i]);
        }
    }

    return str;
}

int main() {
    string str = readAString();

    cout << "\nString after Uppercase:\n";
    cout << upperAllString(str);

    cout << "\nString after Lowercase:\n";
    cout << lowerAllString(str);

    // Wait for user input before closing the console
    system("pause>0");
}