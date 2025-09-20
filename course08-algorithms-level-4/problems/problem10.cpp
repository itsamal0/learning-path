#include <iostream>
#include <iomanip>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print total days
            from the beginning of year.
   From   : Programming Advices – Course 8
   Date   : 2025-09-20
==================================================
*/

const short MONTHS_31[7] = {1, 3, 5, 7, 8, 10, 12};

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getDaysInMonth(short &year, short &month) {
    if (month < 1 || month > 12) return 0;

    if (month == 2) return isLeapYear(year) ? 29 : 28;

    for (int i = 0; i < 7; i++) {
        if (MONTHS_31[i] == month) return 31;
    }

    return 30;
}

short countDaysFromYearStart(short day, short month, short year) {
    short totalDays = 0;
    for (short i = 1; i < month; i++) {
      totalDays += getDaysInMonth(year, i);
    }

    totalDays += day;
    return totalDays;
}

int main() {
    short day = io_utils::readPositiveNumber("Please enter a day: ");
    short month = io_utils::readPositiveNumber("Please enter a month: ");
    short year  = io_utils::readPositiveNumber("Please enter a year: ");

    cout << "\nNumber of days from the beginning of the year is " << countDaysFromYearStart(day, month, year);

    waitForEnter("Press Enter to exit...");

    return 0;
}