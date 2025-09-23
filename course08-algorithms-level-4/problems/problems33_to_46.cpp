#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/date_utils.h"
using namespace std;

/*
==================================================
   Date Problems Solutions: 33 -→ 46
   Each problem illustrates a different date operation:

   problem33: decreaseDateByOneDay (default 10)
   problem34: decreaseDateByXDays (default 10)
   problem35: decreaseDateByOneWeek
   problem36: decreaseDateByXWeeks (default 10)
   problem37: decreaseDateByOneMonth
   problem38: decreaseDateByXMonths (default 5)
   problem39: decreaseDateByOneYear
   problem40: decreaseDateByXYears (default 10)
   problem41: decreaseDateByXYearsFaster (default 10)
   problem42: decreaseDateByOneDecade
   problem43: decreaseDateByXDecades (default 10)
   problem44: decreaseDateByDecadesFaster (default 10)
   problem45: decreaseDateByOneCentury
   problem46: decreaseDateByOneMillennium

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

int main() {
    stDate Date = date_utils::readFullDate();

    cout << "\nDate after : \n";

    // ==== problem33 ====
    Date = date_utils::decreaseDateByOneDay(Date);
    date_utils::printDate(Date, "\n01- Decreasing one day: ");

    // ==== problem34 ====
    Date = date_utils::decreaseDateByXDays(Date, 10);
    date_utils::printDate(Date, "\n02- Decreasing 10 days: ");

    // ==== problem35 ====
    Date = date_utils::decreaseDateByOneWeek(Date);
    date_utils::printDate(Date, "\n03- Decreasing one week: ");

    // ==== problem36 ====
    Date = date_utils::decreaseDateByXWeeks(Date, 10);
    date_utils::printDate(Date, "\n04- Decreasing 10 weeks: ");

    // ==== problem37 ====
    Date = date_utils::decreaseDateByOneMonth(Date);
    date_utils::printDate(Date, "\n05- Decreasing one month: ");

    // ==== problem38 ====
    Date = date_utils::decreaseDateByXMonths(Date, 5);
    date_utils::printDate(Date, "\n06- Decreasing 5 months: ");

    // ==== problem39 ====
    Date = date_utils::decreaseDateByOneYear(Date);
    date_utils::printDate(Date, "\n07- Decreasing one year: ");

    // ==== problem40 ====
    Date = date_utils::decreaseDateByXYears(Date, 10);
    date_utils::printDate(Date, "\n08- Decreasing 10 years: ");

    // ==== problem41 ====
    Date = date_utils::decreaseDateByXYearsFaster(Date, 10);
    date_utils::printDate(Date, "\n09- Decreasing 10 years faster: ");

    // ==== problem42 ====
    Date = date_utils::decreaseDateByOneDecade(Date);
    date_utils::printDate(Date, "\n10- Decreasing one decade: ");

    // ==== problem43 ====
    Date = date_utils::decreaseDateByXDecades(Date, 10);
    date_utils::printDate(Date, "\n11- Decreasing 10 decades: ");

    // ==== problem44 ====
    Date = date_utils::decreaseDateByDecadesFaster(Date, 10);
    date_utils::printDate(Date, "\n12- Decreasing 10 decades faster: ");

    // ==== problem45 ====
    Date = date_utils::decreaseDateByOneCentury(Date);
    date_utils::printDate(Date, "\n13- Decreasing one century: ");

    // ==== problem46 ====
    Date = date_utils::decreaseDateByOneMillennium(Date);
    date_utils::printDate(Date, "\n14- Decreasing one millennium: ");

    waitForEnter("Press Enter to exit...");

    return 0;
}