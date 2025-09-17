#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print number of :
            Days, Hours, Minutes, Seconds
            in a certain month.
   From   : Programming Advices – Course 8
   Date   : 2025-09-17
==================================================
*/

// Arrays for months with 31 and 30 days
const short MONTHS_31[7] = {1, 3, 5, 7, 8, 10, 12};

// Function to check if a given year is a leap year
bool isLeapYear(short year) {
    // A year is a leap year if it is divisible by 400 
    // Or divisible by 4 but not divisible by 100
    // Otherwise, it's not a leap year
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getDaysInMonth(short& year, short& month) {
    if(month < 1 || month > 12)
      return 0;
      
    if(month == 2){
        return isLeapYear(year) ? 29 : 28;
    }

    for (int i = 0; i < 7; i++){
        if(MONTHS_31[i] == month)
            return 31;
    }

    return 30;
}

short getHoursInMonth(short& year, short& month) {
    return getDaysInMonth(year, month) * 24;
}

int getMinutesInMonth(short& year, short& month) {
    return getHoursInMonth(year, month) * 60;
}

int getSecondsInMonth(short& year, short& month) {
    return getMinutesInMonth(year, month) * 60;
}

int main() {
    short year = io_utils::readPositiveNumber("Enter a year to check: ");
    short month = io_utils::readPositiveNumber("Enter a month to check: ");

    cout << "\nNumber of days in month [" << month << "] = " << getDaysInMonth(year, month) << endl;
    cout << "Number of hours in month [" << month << "] = " << getHoursInMonth(year, month) << endl;
    cout << "Number of minutes in month [" << month << "] = " << getMinutesInMonth(year, month) << endl;
    cout << "Number of seconds in month [" << month << "] = " << getSecondsInMonth(year, month) << endl;

    system("pause>0");
    return 0;
}