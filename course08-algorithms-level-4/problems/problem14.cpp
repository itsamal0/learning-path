#include <iostream>
#include <iomanip>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read date1 and
            date2, and check if date1 is 
            equal to date2.
   From   : Programming Advices – Course 8
   Date   : 2025-09-21
==================================================
*/

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

bool isDate1EqualDate2(const stDate& Date1, const stDate& Date2) {
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}


int main() {

  stDate Date1 = readFullDate();
  stDate Date2 = readFullDate();

  if(isDate1EqualDate2(Date1, Date2)) {
    cout << "\nYes Date1 is equal Date2\n";
  }

  else
    cout << "\nNo Date1 is NOT equal Date2\n";

  waitForEnter("Press Enter to exit...");

  return 0;
}