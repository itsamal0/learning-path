#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read two periods
            and check if they overlap or not.
   From   : Programming Advices – Course 8
   Date   : 2025-09-24
==================================================
*/

enum enCompareTwoDates {BEFORE = -1, EQUAL = 0, AFTER = 1};

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

enCompareTwoDates compareTwoDates(stDate Date1, stDate Date2) {
    if (date_utils::isDate1BeforeDate2(Date1, Date2)) 
        return enCompareTwoDates::BEFORE;

    if (date_utils::isDate1EqualDate2(Date1, Date2))
        return enCompareTwoDates::EQUAL;

    return enCompareTwoDates::AFTER;
}

stPeriod readPeriod() {
    stPeriod Period;
    cout << "\nEnter start date: \n";
    Period.StartDate = date_utils::readFullDate();
    cout << "\nEnter end date: \n";
    Period.EndDate = date_utils::readFullDate();

    return Period;
}

bool isOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    if (compareTwoDates(Period2.EndDate, Period1.StartDate) == enCompareTwoDates::BEFORE
        || compareTwoDates(Period2.StartDate, Period1.EndDate) == enCompareTwoDates::AFTER)
        return false;

    return true;
}

int main() {
    cout << "\nEnter period 1: ";
    stPeriod Period1 = readPeriod();

    cout << "\nEnter period 2: ";
    stPeriod Period2 = readPeriod();

    if (isOverlapPeriods(Period1, Period2))
        cout << "\nYes, periods overlap\n";
    else
        cout << "\nNo, periods do not overlap\n";

    waitForEnter("Press Enter to exit...");

    return 0;
}