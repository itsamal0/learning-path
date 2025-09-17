#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to check if a year 
            is a leap year or not.
   From   : Programming Advices – Course 8
   Date   : 2025-09-17
==================================================
*/

// Function to check if a given year is a leap year
bool isLeapYear(int year) {
    // A year is a leap year if it is divisible by 400
    if (year % 400 == 0)
        return true;

    // Or divisible by 4 but not divisible by 100
    if (year % 4 == 0 && year % 100 != 0)
        return true;

    // Otherwise, it's not a leap year
    return false;        
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