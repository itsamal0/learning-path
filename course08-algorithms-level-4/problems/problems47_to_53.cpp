#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Date Problems Solutions: 47 → 53
   Each problem illustrates a different date operation:

   problem47: Check if selected date is end of week
              (implemented as an overloaded function in date_utils.cpp)
   problem48: Check if selected date is end of week
   problem49: Check if selected date is weekend
   problem50: Check if selected date is business day
   problem51: Days until the end of the week
   problem52: Days until the end of the month
   problem53: Days until the end of the year

   From   : Programming Advices – Course 8
   Date   : 2025-09-23
==================================================
*/

void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

int main() {
    stDate Date = date_utils::readFullDate();
    short dayOrderInWeek = date_utils::getDayOfWeekOrder(Date);

    cout << "\nThe selected date is on: " << date_utils::getDayShortName(dayOrderInWeek);
    date_utils::printDate(Date, " ");

    cout << "\nEnd of week? " << (date_utils::isEndOfWeek(dayOrderInWeek) ? "Yes" : "No") << endl;

    cout << "\nWeekend? " << (date_utils::isWeekEnd(dayOrderInWeek) ? "Yes" : "No") << endl;

    cout << "\nBusiness day? " << (date_utils::isBusinessDay(dayOrderInWeek) ? "Yes" : "No") << endl;

    cout << "\nDays until the end of the week: " << date_utils::daysUntilTheEndOfWeek(dayOrderInWeek) << endl;

    cout << "\nDays until the end of the month: " << date_utils::daysUntilTheEndOfMonth(Date) << endl;

    cout << "\nDays until the end of the year: " << date_utils::daysUntilTheEndOfYear(Date) << endl;

    waitForEnter("Press Enter to exit...");

    return 0;
}