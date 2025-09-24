#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
Problem: Write a program to read Vacation Period 
         DateFrom and DateTo and make a function 
         to calculate the actual vacation days.
         Note: Weekends are excluded.
From   : Programming Advices – Course 8
Date   : 2025-09-23
==================================================
*/


// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

short calculateVacationDays(stDate DateFrom, stDate DateTo) {
    short daysCount = 0;

    while (true) {
        if (date_utils::isBusinessDay(date_utils::getDayOfWeekOrder(DateFrom))) {
            daysCount++;
        }

        if (date_utils::isDate1EqualDate2(DateFrom, DateTo)) {
            break;
        }

        DateFrom = date_utils::increaseDateByOneDay(DateFrom);
    }

    return daysCount;
}


int main() {
    cout << "\nVacation starts:";
    stDate DateFrom = date_utils::readFullDate();
    short dayOfWeekOrderOfDateFrom = date_utils::getDayOfWeekOrder(DateFrom);

    cout << "\nVacation ends:";
    stDate DateTo = date_utils::readFullDate();
    short dayOfWeekOrderOfDateTo = date_utils::getDayOfWeekOrder(DateTo);

    cout << "\nVacation from: " << date_utils::getDayShortName(dayOfWeekOrderOfDateFrom);
    date_utils::printDate(DateFrom, ", ");

    cout << "\nVacation to: " << date_utils::getDayShortName(dayOfWeekOrderOfDateTo);
    date_utils::printDate(DateTo, ", ");

    cout << "\n\nActucal vacation days is: " << calculateVacationDays(DateFrom, DateTo) << endl;

    waitForEnter("Press Enter to exit...");

    return 0;
}