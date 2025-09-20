#include <iostream>
#include <iomanip>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print month calendar
   From   : Programming Advices – Course 8
   Date   : 2025-09-20
==================================================
*/

const short MONTHS_31[7] = {1, 3, 5, 7, 8, 10, 12};

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getDaysInMonth(short &year, short &month) {
    if (month < 1 || month > 12) return 0;

    if (month == 2) return isLeapYear(year) ? 29 : 28;

    for (int i = 0; i < 7; i++) {
        if (MONTHS_31[i] == month) return 31;
    }

    return 30;
}

short getDayOfWeekOrder(short year, short month, short day) {
    short a = (14 - month) / 12;
    year  = year - a;
    month = month + (12 * a) - 2;
    return (day + year + (year / 4) - (year / 100) + (year / 400) + (31 * month / 12)) % 7;
}

string getMonthShortName(short month) {
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return months[month - 1];
}

void printMonthCalendar(short year, short month) {
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    string monthShortName = getMonthShortName(month);
    short dayOrder = getDayOfWeekOrder(year, month, 1);
    short daysInMonth = getDaysInMonth(year, month);

    cout << "\n  _______________" << monthShortName << "_______________\n\n";
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int i;
    for (i = 0; i < dayOrder; i++) {
        cout << "     ";
    }

    for (int j = 1; j <= daysInMonth; j++) {
        cout << setw(5) << j;
        if (++i == 7) {
            i = 0;
            cout << "\n";
        }
    }

    cout << "\n  _________________________________\n";
}

int main() {
    short year  = io_utils::readPositiveNumber("Please enter a year: ");
    short month = io_utils::readPositiveNumber("Please enter a month: ");

    printMonthCalendar(year, month);

    waitForEnter("Press Enter to exit...");

    return 0;
}