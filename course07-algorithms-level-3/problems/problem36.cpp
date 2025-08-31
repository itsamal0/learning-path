#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to count the number 
            of words in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Count the number of words in a string
short countEachWordInString(string str) {
    string delim = " ";
    short pos = 0, countWords = 0;
    string word = "";

    while ((pos = str.find(delim)) != string::npos) {
        word = str.substr(0, pos);

        if (word != "") {
            countWords++;
        }

        str.erase(0, pos + delim.length());
    }

    if (str != "") {
        countWords++;
    }

    return countWords;
}

int main() {
    // Read string from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");
    cout << "\nThe number of words in string is: " 
         << countEachWordInString(str);

    // Wait for user input before closing the console
    system("pause>0");
}