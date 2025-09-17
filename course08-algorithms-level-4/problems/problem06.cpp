#include <iostream>
#include <algorithm>
#include <iterator>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print number of Days 
            in a certain month, with two lines of code.
   From   : Programming Advices – Course 8
   Date   : 2025-09-17
==================================================
*/

// Arrays for months with 31 and 30 days
const short MONTHS_31[7] = {1, 3, 5, 7, 8, 10, 12};

// Function to check if a given year is a leap year
bool isLeapYear(short year) {
    // A year is a leap year if it is divisible by 400 
    // Or divisible by 4 but not divisible by 100
    // Otherwise, it's not a leap year
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getDaysInMonth(short& year, short& month) {
    if(month < 1 || month > 12) return 0;

    // Nested conditional expression:
    // 1) If month == 2 → check leap year (29 or 28).
    // 2) Else → check if month exists in MONTHS_31 → 31, otherwise 30.
    return (month == 2) ? (isLeapYear(year) ? 29 : 28)
                        : (find(begin(MONTHS_31), end(MONTHS_31), month) != end(MONTHS_31) ? 31 : 30);
}

int main() {
    short year = io_utils::readPositiveNumber("Enter a year to check: ");
    short month = io_utils::readPositiveNumber("Enter a month to check: ");

    cout << "\nNumber of days in month [" << month << "] = " << getDaysInMonth(year, month) << endl;

    system("pause>0");
    return 0;
}