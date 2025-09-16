#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to trim spaces
            from left, right, and both sides of a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main()
{
    // Read string from user using io_utils
    string str = io_utils::readString("Please enter your string ?");

    cout << "\nTrim left  = " << string_utils::trimLeft(str);
    cout << "\nTrim right = " << string_utils::trimRight(str);
    cout << "\nTrim both  = " << string_utils::trim(str);

    // Wait for user input before closing the console
    system("pause>0");
}