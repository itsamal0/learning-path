#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a character and then 
	    invert it's case.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read a character from user using helperFunctions
    char c = helperFunctions::readLetter("Please enter a character ?");

    cout << "\nCharacter after inverting case:\n";
    cout << helperFunctions::inverLetterCase(c);


    // Wait for user input before closing the console
    system("pause>0");
}