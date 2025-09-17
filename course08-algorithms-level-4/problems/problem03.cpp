#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Solve lead year problem (problem02) with
            one line of code only.
   From   : Programming Advices – Course 8
   Date   : 2025-09-17
==================================================
*/

// Function to check if a given year is a leap year
bool isLeapYear(int year) {
    // A year is a leap year if it is divisible by 400 
    // Or divisible by 4 but not divisible by 100
    // Otherwise, it's not a leap year
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    int year = io_utils::readPositiveNumber("Enter a year: ");

    if (isLeapYear(year)) {
        cout << "\nYes, year [" << year << "] is a leap year.\n";
    } else {
        cout << "\nNo, year [" << year << "] is NOT a leap year.\n";
    }

    system("pause>0");

    return 0;
}