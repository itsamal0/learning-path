#include <iostream>
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read two periods
            then count overlap days.
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

stPeriod readPeriod() {
    stPeriod Period;
    cout << "\nEnter start date: \n";
    Period.StartDate = date_utils::readFullDate();
    cout << "\nEnter end date: ";
    Period.EndDate = date_utils::readFullDate();

    return Period;
}

short overLapDays(stPeriod Period1, stPeriod Period2) {
    short overLapDays = 0;

    if(!date_utils::isOverlapPeriods(Period1, Period2)) return 0;

    if(date_utils::periodLengthInDays(Period1, true) < date_utils::periodLengthInDays(Period2, true)) {
        while(!date_utils::isDate1AfterDate2(Period1.StartDate, Period1.EndDate)) {
            if(date_utils::isDateWithinPeriod(Period2, Period1.StartDate)) 
                overLapDays++;
            Period1.StartDate = date_utils::increaseDateByOneDay(Period1.StartDate);
        }
    } 
    else {
        while(!date_utils::isDate1AfterDate2(Period2.StartDate, Period2.EndDate)) {
            if(date_utils::isDateWithinPeriod(Period1, Period2.StartDate)) 
                overLapDays++;
            Period2.StartDate = date_utils::increaseDateByOneDay(Period2.StartDate);
        }
    }

    return overLapDays;
}

int main() {
    cout << "\nEnter period 1: ";
    stPeriod Period1 = readPeriod();

    cout << "\nEnter period 2: ";
    stPeriod Period2 = readPeriod();

    cout << "\nOverlap Days = " << overLapDays(Period1, Period2) << endl; 

    waitForEnter("Press Enter to exit...");

    return 0;
}