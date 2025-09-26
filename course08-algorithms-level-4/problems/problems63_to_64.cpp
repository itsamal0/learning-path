#include <iostream>
#include <vector>
#include "../../helpers/date_utils.h"
#include "../../helpers/io_utils.h"
#include "../../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem63: 
   - Read date as string (dd/mm/yyyy).
   - Convert it to date structure.
   - Print day, month, year separately.

   Problem64:
   - Convert structure back to string and print it.

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

stDate stringToDate(string strDate) {
    stDate Date;
    vector<string> vDate = string_utils::splitString(strDate, "/");

    Date.Day   = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year  = stoi(vDate[2]);

    return Date;
}

string dateToString(stDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

void printDateDetails(const stDate& Date) {
    cout << "Day: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;
}

int main() {
  
    string strDate = io_utils::readString("\nEnter a date dd/mm/yyyy: ");
    stDate Date = stringToDate(strDate);

    printDateDetails(Date);

    cout << "\nYou Entered: " << dateToString(Date);

    waitForEnter("\nPress Enter to exit...");

    return 0;
}