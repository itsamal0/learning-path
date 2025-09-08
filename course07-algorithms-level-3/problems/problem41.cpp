#include <iostream>
#include <string>
#include <vector>
#include "../helpers/string_utils.h"
#include "../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Reverse the order of words in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read string from user using io_utils
    string str = io_utils::readString("Please enter your string ?");

    // Reverse words using string_utils function
    cout << "\nString after reversing words: " << endl;
    cout << string_utils::reverseWordsInString(str);

    // Wait for user input before closing
    system("pause>0");
}