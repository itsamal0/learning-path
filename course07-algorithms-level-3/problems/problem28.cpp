#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/char_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a string and
            invert the case of all its letters.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main()
{
    // Read string from user using io_utils
    string str = io_utils::readString("Please enter your string ?");

    // Invert case of all letters using char_utils
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = char_utils::invertLetterCase(str[i]);
    }

    cout << "\nString after inverting all letters case:\n";
    cout << str;

    // Wait for user input before closing the console
    system("pause>0");
}