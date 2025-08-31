#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to check if a character 
            is a vowel (a, e, i, o, u).
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Check if a character is a vowel
bool isVowel(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

int main() {
    // Read character from user using helperFunctions
    char letter = helperFunctions::readLetter("Please enter a character ?");

    if (isVowel(letter)) {
        cout << "\nYes, letter '" << letter << "' is a vowel";
    } else {
        cout << "\nNo, letter '" << letter << "' is NOT a vowel";
    }

    // Wait for user input before closing the console
    system("pause>0");
}