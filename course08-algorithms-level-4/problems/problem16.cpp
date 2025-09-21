#include <iostream>
#include <iomanip>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a date and make
            a function to increase date by one day.
   From   : Programming Advices – Course 8
   Date   : 2025-09-21
==================================================
*/

const short MONTHS_31[7] = {1, 3, 5, 7, 8, 10, 12};

struct stDate {
  short Day;
  short Month;
  short Year;
};

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

stDate readFullDate() {
    stDate Date;

    Date.Day = io_utils::readPositiveNumber("\nPlease enter a day: ");
    Date.Month = io_utils::readPositiveNumber("\nPlease enter a month: ");
    Date.Year = io_utils::readPositiveNumber("\nPlease enter a year: ");

    return Date;
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

bool isLastDayInMonth(stDate& Date) {
    return (Date.Day == getDaysInMonth(Date.Year, Date.Month));
}

bool isLastMonthInYear(short month) {
    return month == 12;
}

stDate increaseDateByOneDay(stDate& Date) {
    if (isLastDayInMonth(Date) && isLastMonthInYear(Date.Month)) {
        Date.Day = 1;
        Date.Month = 1;
        Date.Year++;
        return Date;
    }

    if (isLastDayInMonth(Date)) {
       Date.Day = 1;
       Date.Month++;
    }

    else {
      Date.Day++;
    }

    return Date;
}

int main() {
    stDate Date = readFullDate();

    Date = increaseDateByOneDay(Date);
    cout << "\nDate after adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    waitForEnter("Press Enter to exit...");

    return 0;
}