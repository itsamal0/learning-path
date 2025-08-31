#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to count how many times 
            a specific character appears in a string,
            with optional case-insensitive counting.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Count occurrences of a specific character in a string
short countLetter(string str, char letter, bool matchCase = true) {
    short counter = 0;

    for (int i = 0; i < str.length(); i++) {
        if (matchCase) {
            if (str[i] == letter) {
                counter++;
            }
        } else {
            if (tolower(str[i]) == tolower(letter)) {
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    // Read string and character from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");
    char letter = helperFunctions::readLetter("Please enter a character ?");

    cout << "\nLetter '" << letter << "' count = " << countLetter(str, letter);
    cout << "\nLetter '" << letter << "' or '"
         << helperFunctions::inverLetterCase(letter)
         << "' = " << countLetter(str, letter, false);

    // Wait for user input before closing the console
    system("pause>0");
}