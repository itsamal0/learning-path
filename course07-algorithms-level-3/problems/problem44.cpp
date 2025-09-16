#include <iostream>
#include <string>
#include <vector>
#include "../../helpers/io_utils.h"
#include "../../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Remove all punctuation characters
            from a string using a custom function.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main()
{
    // Read original text from user
    string originalText = io_utils::readString("\nPlease enter your text:");

    // Show original string
    cout << "\nOriginal string:\n"
         << originalText << endl;

    // Remove punctuations using helperFunctions
    cout << "\n:Punctuation removed:\n"
         << string_utils::removePunctuationsFromString(originalText) << endl;

    // Wait for user input before closing
    system("pause>0");
}