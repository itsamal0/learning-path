#include <iostream>
#include <string>
#include <vector>
#include "../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Replace all occurrences of a word in a string
            with another word using built-in string functions.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Replace all occurrences of targetWord with replacementWord
string replaceWordInStringUsingBuiltInFunction(string str, string targetWord, string replacementWord) {
    short pos = str.find(targetWord);

    while (pos != string::npos) {
        str.replace(pos, targetWord.length(), replacementWord);
        pos = str.find(targetWord);
    }
    
    return str;
}

int main() {
    // Read string and words from user using io_utils
    string str = io_utils::readString("\nPlease enter your text:");
    string targetWord = io_utils::readString("\nEnter the word you want to replace:");
    string replacementWord = io_utils::readString("\nEnter the replacement word:");

    cout << "\nOriginal string:\n" << str << endl;

    cout << "\nString after replacing:\n" 
         << replaceWordInStringUsingBuiltInFunction(str, targetWord, replacementWord) 
         << endl;

    // Wait for user input before closing
    system("pause>0");
}