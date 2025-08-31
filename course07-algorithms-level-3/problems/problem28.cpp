#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a string and 
            invert the case of all its letters.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read string from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");

    // Invert case of all letters using helperFunctions
    for (int i = 0; i < str.length(); i++) {
        str[i] = helperFunctions::inverLetterCase(str[i]);
    }

    cout << "\nString after inverting all letters case:\n";
    cout << str;

    // Wait for user input before closing the console
    system("pause>0");
}