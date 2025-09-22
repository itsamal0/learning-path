#include <iostream>
#include <ctime>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to calculate
            your age in days.
   From   : Programming Advices – Course 8
   Date   : 2025-09-22
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

stDate getSystemDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stDate Date;
    Date.Day   = ltm->tm_mday;     
    Date.Month = 1 + ltm->tm_mon;   
    Date.Year  = 1900 + ltm->tm_year;

    return Date;
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

  cout << "\nPlease enter your date of birth:\n";

  stDate BirthDate = readFullDate();
  stDate Today = getSystemDate();

  cout << "\nYour age is: " << getDifferenceInDays(BirthDate, Today) << " day(s)\n";
  

  waitForEnter("Press Enter to exit...");

  return 0;
}