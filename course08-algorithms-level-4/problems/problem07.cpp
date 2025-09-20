#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a date, and 
            print the day name of week.
   From   : Programming Advices – Course 8
   Date   : 2025-09-20
==================================================
*/

short getDayOfWeekOrder(short year, short month, short day) {
    short a = (14 - month) / 12;

    year  = year - a;
    month = month + (12 * a) - 2;

    return (day + year + (year / 4) - (year / 100) + (year / 400) + (31 * month / 12)) % 7;
}

string getDayShortName(short day) {
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return days[day];
}

void printDateInfo(short year, short month, short day, short dayOrder) {
    cout << "\nDate       : " << day << "/" << month << "/" << year;
    cout << "\nDay Order  : " << dayOrder;
    cout << "\nDay Name   : " << getDayShortName(dayOrder);
}

int main() {
    short year  = io_utils::readPositiveNumber("Please enter a year: ");
    short month = io_utils::readPositiveNumber("Please enter a month: ");
    short day   = io_utils::readPositiveNumber("Please enter a day: ");

    short dayOrder = getDayOfWeekOrder(year, month, day);

    printDateInfo(year, month, day, dayOrder);

    system("pause>0");
    return 0;
}