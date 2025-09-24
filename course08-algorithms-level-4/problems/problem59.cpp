#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a period
            and calculate period length in days.
   From   : Programming Advices – Course 8
   Date   : 2025-09-24
==================================================
*/

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

stPeriod readPeriod() {
    stPeriod Period;
    cout << "\nEnter start date: \n";
    Period.StartDate = date_utils::readFullDate();
    cout << "\nEnter end date: ";
    Period.EndDate = date_utils::readFullDate();

    return Period;
}

short periodLengthInDays(stPeriod Period1, bool includeEndDay = false) {
    return date_utils::getDifferenceInDays(Period1.StartDate, Period1.EndDate, includeEndDay);
}

int main() {
    cout << "\nEnter Period 1:";
    stPeriod Period1 = readPeriod();

    cout << "\nPeriod Length is: " 
     << periodLengthInDays(Period1);

    cout << "\nPeriod Length (Including End Date) is: " 
     << periodLengthInDays(Period1, true);


    waitForEnter("Press Enter to exit...");

    return 0;
}