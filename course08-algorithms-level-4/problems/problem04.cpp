#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print number of :
            Days, Hours, Minutes, Seconds
            in a cretain year.
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

short getDaysInYear(int& year) {
    return isLeapYear(year) ? 366 : 365;
}

short getHoursInYear(int& year) {
    return getDaysInYear(year) * 24;
}

int getMinutesInYear(int& year) {
    return getHoursInYear(year) * 60;
}

int getSecondsInYear(int& year) {
    return getMinutesInYear(year) * 60;
}

int main() {
    int year = io_utils::readPositiveNumber("Enter a year: ");

    cout << "\nNumber of days in year [" << year << "] = " << getDaysInYear(year) << endl;
    cout << "\nNumber of hours in year [" << year << "] = " << getHoursInYear(year) << endl;
    cout << "\nNumber of minutes in year [" << year << "] = " << getMinutesInYear(year) << endl;
    cout << "\nNumber of seconds in year [" << year << "] = " << getSecondsInYear(year) << endl;

    system("pause>0");

    return 0;
}