#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
Problem: Write a program to read Vacation start 
         DateFrom and VacationDays and make a function 
         to calculate the vacation end date.
         Note: Weekends are excluded.
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

stDate calculateVacationEndDate(stDate DateFrom, short vacationDays) {
    stDate DateTo = DateFrom;
    short dayOfWeekOrder = date_utils::getDayOfWeekOrder(DateTo);

    while (vacationDays > 0) {
        DateTo = date_utils::increaseDateByOneDay(DateTo);
        dayOfWeekOrder = date_utils::getDayOfWeekOrder(DateTo);

        if (date_utils::isBusinessDay(dayOfWeekOrder)) {
            vacationDays--;
        }
    }

    return DateTo;
}

int main() {
    cout << "\nVacation starts:";
    stDate DateFrom = date_utils::readFullDate();
    
    short vacationDays = io_utils::readPositiveNumber("Please enter vacation days: ");

    stDate DateTo = calculateVacationEndDate(DateFrom, vacationDays);
    short dayOfWeekOrderOfDateTo = date_utils::getDayOfWeekOrder(DateTo);

    cout << "\n\nVacation ends in: " << date_utils::getDayShortName(dayOfWeekOrderOfDateTo);
    date_utils::printDate(DateTo, ", ");

    waitForEnter("Press Enter to exit...");

    return 0;
}