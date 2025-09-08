#include <iostream>
#include "../helpers/io_utils.h"
#include "../helpers/char_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to check if a character 
            is a vowel (a, e, i, o, u).
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

bool isVowel(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

int main() {
    char letter = io_utils::readLetter("Please enter a character ? ");

    if (isVowel(letter)) {
        cout << "\nYes, letter '" << letter << "' is a vowel";
    } else {
        cout << "\nNo, letter '" << letter << "' is NOT a vowel";
    }

    system("pause>0");
}