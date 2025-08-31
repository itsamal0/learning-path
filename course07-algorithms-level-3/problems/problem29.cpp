#include <iostream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to count letters in a string.
            Count capital letters, small letters, and total letters.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

enum enWhatToCount { SmallLetters = 1, CapitalLetters = 2, All = 3 };

// Count letters based on the specified type
short countLetters(string str, enWhatToCount whatToCount = enWhatToCount::All) {
    if (whatToCount == enWhatToCount::All) {
        return str.length();
    }

    short counter = 0;
    for (int i = 0; i < str.length(); i++) {
        if (whatToCount == enWhatToCount::CapitalLetters && isupper(str[i])) {
            counter++;
        }
        if (whatToCount == enWhatToCount::SmallLetters && islower(str[i])) {
            counter++;
        }
    }

    return counter;
}

int main() {
    // Read string from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");

    cout << "\nString length = " << countLetters(str) << endl;
    cout << "Capital letters count = " << countLetters(str, enWhatToCount::CapitalLetters) << endl;
    cout << "Small letters count = " << countLetters(str, enWhatToCount::SmallLetters) << endl;

    // Wait for user input before closing the console
    system("pause>0");
}