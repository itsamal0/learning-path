#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to convert a string  
            to uppercase and to lowercase.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read string from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");

    cout << "\nString after Uppercase:\n";
    cout << helperFunctions::upperAllString(str);

    cout << "\nString after Lowercase:\n";
    cout << helperFunctions::lowerAllString(str);

    // Wait for user input before closing the console
    system("pause>0");
}