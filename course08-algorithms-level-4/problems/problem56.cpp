#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read date1 and
            date2, and check if date1 is 
            after date2.
   From   : Programming Advices – Course 8
   Date   : 2025-09-24
==================================================
*/

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

bool isDate1AfterDate2(const stDate& Date1, const stDate& Date2) {
    return (!date_utils::isDate1BeforeDate2(Date1, Date2) && !date_utils::isDate1EqualDate2(Date1, Date2));
}

int main() {
  cout << "\nEnter date1: ";
  stDate Date1 = date_utils::readFullDate();

  cout << "\nEnter date2: ";
  stDate Date2 = date_utils::readFullDate();

  if(isDate1AfterDate2(Date1, Date2)) {
    cout << "\nYes Date1 is after Date2\n";
  }

  else
    cout << "\nNo Date1 is NOT after Date2\n";

  waitForEnter("Press Enter to exit...");

  return 0;
}