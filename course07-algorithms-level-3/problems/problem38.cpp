#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to trim spaces 
            from left, right, and both sides of a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read string from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");

    cout << "\nTrim left  = " << helperFunctions::trimLeft(str);
    cout << "\nTrim right = " << helperFunctions::trimRight(str);
    cout << "\nTrim both  = " << helperFunctions::trim(str);

    // Wait for user input before closing the console
    system("pause>0");
}