#include <iostream>
#include <iomanip>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read date and
            read how many days to add to it, 
            then print the results.
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

short countDaysFromYearStart(short day, short month, short year) {
    short totalDays = 0;
    for (short i = 1; i < month; i++) {
      totalDays += getDaysInMonth(year, i);
    }

    totalDays += day;
    return totalDays;
}

stDate dateAddDays(short days, short year){
  stDate Date;
  short remainingDays = days;
  short monthDays = 0;
  short yearDays = 0;

  Date.Year = year;
  Date.Month = 1;

  while(true){
    monthDays = getDaysInMonth(Date.Year, Date.Month);
    yearDays = getDaysInYear(Date.Year);

    if(remainingDays > yearDays) { 
      remainingDays -= yearDays;
      Date.Year++;
    }

    else if (remainingDays > monthDays && remainingDays < yearDays){
      remainingDays -= monthDays;
      Date.Month++;
    }

    else {
      Date.Day = remainingDays;
      break;
    }
  }

  return Date;
}

int main() {
    short day = io_utils::readPositiveNumber("Please enter a day: ");
    short month = io_utils::readPositiveNumber("Please enter a month: ");
    short year  = io_utils::readPositiveNumber("Please enter a year: ");
    short days = io_utils::readPositiveNumber("How many days to add ? ");
    short daysOrderInYear = countDaysFromYearStart(day, month, year);
    stDate Date;

    Date = dateAddDays(daysOrderInYear + days, year);

    cout << "\nDate after adding [" << days << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    waitForEnter("Press Enter to exit...");

    return 0;
}