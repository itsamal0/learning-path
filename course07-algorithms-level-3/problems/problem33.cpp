#include <iostream>
#include "../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to count the number of   
            vowels in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Check if a character is a vowel
bool isVowel(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

// Count vowels in a string
short countVowelsLetters(string str) {
    short counter = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isVowel(str[i])) {
            counter++;
        }
    }
    return counter;
}

int main() {
    // Read string from user using io_utils
    string str = io_utils::readString("Please enter your string ?");
    short numberOfVowels = countVowelsLetters(str);

    if (numberOfVowels == 0) {
        cout << "\nThere is no vowels\n";
    } else {
        cout << "\nNumber of vowels is: " << numberOfVowels;
    }

    // Wait for user input before closing the console
    system("pause>0");
}