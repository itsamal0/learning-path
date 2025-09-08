#include <iostream>
#include "../helpers/io_utils.h"
#include "../helpers/char_utils.h"
using namespace std;

/*
==================================================
   Problem: Read a character and invert its case
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read a character from user using io_utils
    char c = io_utils::readLetter("Please enter a character ? ");

    cout << "\nCharacter after inverting case:\n";
    cout << char_utils::invertLetterCase(c);

    // Wait for user input before closing the console
    system("pause>0");
}