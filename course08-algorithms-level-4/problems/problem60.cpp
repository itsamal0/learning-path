#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a period
            and date, and check if date is within
            period or not.
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

bool isDate1AfterDate2(const stDate& Date1, const stDate& Date2) {
    return (!date_utils::isDate1BeforeDate2(Date1, Date2) && !date_utils::isDate1EqualDate2(Date1, Date2));
}

bool isDateWithinPeriod(stPeriod Period, stDate Date) {
    return (!date_utils::isDate1BeforeDate2(Date, Period.StartDate)
            && !date_utils::isDate1AfterDate2(Date, Period.EndDate));
}

int main() {
    cout << "\nEnter Period:\n";
    stPeriod Period = readPeriod();

    cout << "\nEnter Date to check: ";
    stDate Date = date_utils::readFullDate();

    if (isDateWithinPeriod(Period, Date))
        cout << "\nYes, the date is within the period.\n";
    else
        cout << "\nNo, the date is not within the period.\n";

    waitForEnter("Press Enter to exit...");

    return 0;
}
