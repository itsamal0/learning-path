#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read date1 and
            date2, and write a function to compare
            dates, it should return:
            - -1 Before
            - 0 Equal
            - 1 After
   From   : Programming Advices – Course 8
   Date   : 2025-09-24
==================================================
*/

enum enCompareTwoDates {BEFORE = -1, EQUAL = 0, AFTER = 1};

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

enCompareTwoDates compareTwoDates(stDate Date1, stDate Date2) {
    if (date_utils::isDate1BeforeDate2(Date1, Date2)) 
      return enCompareTwoDates::BEFORE;

    if(date_utils::isDate1EqualDate2(Date1, Date2))
      return enCompareTwoDates::EQUAL;

    return enCompareTwoDates::AFTER;
}

int main() {
    cout << "\nEnter date1: ";
    stDate Date1 = date_utils::readFullDate();

    cout << "\nEnter date2: ";
    stDate Date2 = date_utils::readFullDate();

    cout << "\nCompare result: " << compareTwoDates(Date1, Date2) << endl;

    waitForEnter("Press Enter to exit...");

    return 0;
}