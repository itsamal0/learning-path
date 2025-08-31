#include <iostream>
#include <string>
#include <vector>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Reverse the order of words in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read string from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");

    // Reverse words using helperFunctions function
    cout << "\nString after reversing words: " << endl;
    cout << helperFunctions::reverseWordsInString(str);

    // Wait for user input before closing
    system("pause>0");
}