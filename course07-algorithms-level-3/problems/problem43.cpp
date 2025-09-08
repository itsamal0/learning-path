#include <iostream>
#include <string>
#include <vector>
#include "../helpers/io_utils.h"
#include "../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to replacing words in a string
            using a custom replace function with 
            optional match case.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read original text and target/replacement words from user
    string originalText   = io_utils::readString("\nPlease enter your text:");
    string targetWord     = io_utils::readString("\nEnter the word you want to replace:");
    string replacementWord= io_utils::readString("\nEnter the replacement word:");

    // Show original string
    cout << "\nOriginal string:\n" << originalText << endl;

    // Replace using match case
    cout << "\nString after replacing using match case:\n" 
         << string_utils::replace(originalText, targetWord, replacementWord) << endl;

    // Replace without match case
    cout << "\nString after replacing without match case:\n" 
         << string_utils::replace(originalText, targetWord, replacementWord, false) << endl;

    // Wait for user input before closing
    system("pause>0");
}