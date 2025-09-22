#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Date Problems Solutions: 20 -→ 33
   Each problem illustrates a different date operation:

   problem20: increaseDateByXDays (default 10)
   problem21: increaseDateByOneWeek
   problem22: increaseDateByXWeeks (default 10)
   problem23: increaseDateByOneMonth
   problem24: increaseDateByXMonths (default 5)
   problem25: increaseDateByOneYear
   problem26: increaseDateByXYears (default 10)
   problem27: increaseDateByXYearsFaster (default 10)
   problem28: increaseDateByOneDecade
   problem29: increaseDateByXDecades (default 10)
   problem30: increaseDateByDecadesFaster (default 10)
   problem31: increaseDateByOneCentury
   problem32: increaseDateByOneMillennium
==================================================
*/

// Wait for user to press Enter before exiting
void waitForEnter(string message) {
    cout << "\n" << message;
    cin.ignore();
    cin.get();
}

int main() {
    stDate Date = date_utils::readFullDate();
    
    cout << "\nDate after : \n";

    Date = date_utils::increaseDateByOneDay(Date);
    date_utils::printDate(Date, "\n01- Adding one day: ");

    // ==== problem20 ====
    Date = date_utils::increaseDateByXDays(Date);
    date_utils::printDate(Date, "\n02- Adding 10 days: ");

    // ==== problem21 ====
    Date = date_utils::increaseDateByOneWeek(Date);
    date_utils::printDate(Date, "\n03- Adding one week: ");

    // ==== problem22 ====
    Date = date_utils::increaseDateByXWeeks(Date);
    date_utils::printDate(Date, "\n04- Adding 10 weeks: ");

    // ==== problem23 ====
    Date = date_utils::increaseDateByOneMonth(Date);
    date_utils::printDate(Date, "\n05- Adding one month: ");

    // ==== problem24 ====
    Date = date_utils::increaseDateByXMonths(Date);
    date_utils::printDate(Date, "\n06- Adding 5 months: ");

    // ==== problem25 ====
    Date = date_utils::increaseDateByOneYear(Date);
    date_utils::printDate(Date, "\n07- Adding one year: ");

    // ==== problem26 ====
    Date = date_utils::increaseDateByXYears(Date);
    date_utils::printDate(Date, "\n08- Adding 10 years: ");

    // ==== problem27 ====
    Date = date_utils::increaseDateByXYearsFaster(Date);
    date_utils::printDate(Date, "\n09- Adding 10 years faster: ");

    // ==== problem28 ====
    Date = date_utils::increaseDateByOneDecade(Date);
    date_utils::printDate(Date, "\n10- Adding one decade: ");

    // ==== problem29 ====
    Date = date_utils::increaseDateByXDecades(Date);
    date_utils::printDate(Date, "\n11- Adding 10 decades: ");

    // ==== problem30 ====
    Date = date_utils::increaseDateByDecadesFaster(Date);
    date_utils::printDate(Date, "\n12- Adding 10 decades faster: ");

    // ==== problem31 ====
    Date = date_utils::increaseDateByOneCentury(Date);
    date_utils::printDate(Date, "\n13- Adding one century: ");

    // ==== problem32 ====
    Date = date_utils::increaseDateByOneMillennium(Date);
    date_utils::printDate(Date, "\n14- Adding one millennium: ");

    waitForEnter("Press Enter to exit...");

    return 0;
}