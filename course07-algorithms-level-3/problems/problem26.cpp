#include <iostream>
#include "../helpers/io_utils.h"
#include "../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Convert a string to uppercase and lowercase
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Read string from user using io_utils library
    string str = io_utils::readString("Please enter your string ? ");

    cout << "\nString after Uppercase:\n";
    cout << string_utils::upperAllString(str);

    cout << "\nString after Lowercase:\n";
    cout << string_utils::lowerAllString(str);

    // Wait for user input before closing the console
    system("pause>0");
}