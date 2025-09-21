#include <iostream>
#include <iomanip>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a date1, date2
            and make a function to calculate a 
            difference in days.
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

short getDaysInYear(short year) {
    return isLeapYear(year) ? 366 : 365;
}

short getDaysInMonth(short &year, short &month) {
    if (month < 1 || month > 12) return 0;

    if (month == 2) return isLeapYear(year) ? 29 : 28;

    for (int i = 0; i < 7; i++) {
        if (MONTHS_31[i] == month) return 31;
    }

    return 30;
}

int getDifferenceInDays(stDate& Date1, stDate Date2, bool includeEndDay = false) {
  int days = 0;
  while (Date1.Year != Date2.Year) {
    days += getDaysInYear(Date2.Year);
    Date2.Year--;
  }

  while (Date1.Month != Date2.Month) {
    days += getDaysInMonth(Date2.Year, Date2.Month);
    Date2.Month--;
  }

  while (Date1.Day != Date2.Day) {
    days++;
    Date2.Day--;
  } 

  return includeEndDay ? ++days : days;
}

int main() {
    stDate Date1 = readFullDate();
    stDate Date2 = readFullDate();

    cout << "\nDifference is: " << getDifferenceInDays(Date1, Date2) << " day(s)\n";
    cout << "\nDifference (including end day) is: " << getDifferenceInDays(Date1, Date2, true) << " day(s)\n";

    waitForEnter("Press Enter to exit...");

    return 0;
}