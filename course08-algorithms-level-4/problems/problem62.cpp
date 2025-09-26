#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a date and
            write a function to validate this date.
   From   : Programming Advices – Course 8
   Date   : 2025-09-26
==================================================
*/

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

bool isValidDate(stDate Date) {
    if(Date.Month < 1 || Date.Month > 12) return false;

    return Date.Day <= date_utils::getDaysInMonth(Date.Year, Date.Month);
}

int main() {
    cout << "\nEnter a date: ";
    stDate Date = date_utils::readFullDate();

    if(isValidDate(Date))
      cout << "\nYes, Date is a valid date.\n";

    else cout << "\nNo, Date is NOT a valid date.\n";

    waitForEnter("Press Enter to exit...");

    return 0;
}