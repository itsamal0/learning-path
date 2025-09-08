#include <iostream>
#include "../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to count how many times   
            a specific character appears in a string.  
   From   : Programming Advices – Course 7  
   Date   : 2025-08-31  
==================================================
*/

// Count occurrences of a specific character in a string
short countLetter(string str, char letter) {
    short counter = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == letter) {
            counter++;
        }
    }

    return counter;
}

int main() {
    // Read string and character from user using io_utils
    string str = io_utils::readString("Please enter your string ?");
    char letter = io_utils::readLetter("Please enter a character ?");

    cout << "\nLetter '" << letter << "' count = " << countLetter(str, letter) << endl;

    // Wait for user input before closing the console
    system("pause>0");
}