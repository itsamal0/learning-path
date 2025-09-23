#include "date_utils.h"
#include "io_utils.h"
#include <algorithm>
using namespace std;

namespace date_utils {

// ==== Constants ====
const short MONTHS_31[7] = {1, 3, 5, 7, 8, 10, 12};

    // ==== Year Functions ====
    bool isLeapYear(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }

    short getDaysInYear(int year) {
        return isLeapYear(year) ? 366 : 365;
    }

    short getHoursInYear(int year) {
        return getDaysInYear(year) * 24;
    }

    int getMinutesInYear(int year) {
        return getHoursInYear(year) * 60;
    }

    int getSecondsInYear(int year) {
        return getMinutesInYear(year) * 60;
    }

    // ==== Month Functions ====
    short getDaysInMonth(short year, short month) {
        return (month == 2) ? (isLeapYear(year) ? 29 : 28)
                            : (find(begin(MONTHS_31), end(MONTHS_31), month) != end(MONTHS_31) ? 31 : 30);
    }

    short getHoursInMonth(short year, short month) {
        return getDaysInMonth(year, month) * 24;
    }

    int getMinutesInMonth(short year, short month) {
        return getHoursInMonth(year, month) * 60;
    }

    int getSecondsInMonth(short year, short month) {
        return getMinutesInMonth(year, month) * 60;
    }

    string getMonthShortName(short month) {
        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        if(month < 1 || month > 12) return "Invalid";
        return months[month - 1];
    }

    // ==== Week Functions ====
    short getDayOfWeekOrder(short year, short month, short day) {
        short a = (14 - month) / 12;
        year  = year - a;
        month = month + (12 * a) - 2;
        return (day + year + (year / 4) - (year / 100) + (year / 400) + (31 * month / 12)) % 7;
    }

    // ==== problem47 ====
    // Overloaded getDayOfWeekOrder: Accepts a stDate structure
    short getDayOfWeekOrder(stDate Date) {
        return getDayOfWeekOrder(Date.Year, Date.Month, Date.Day);
    }

    string getDayShortName(short day) {
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return days[day];
    }

    // ==== Week / Day Utilities ====

    // Check if the day is the end of the week (Saturday)
    bool isEndOfWeek(short dayOrderInWeek) { 
        return dayOrderInWeek == 6; 
    }

    // Check if the day is a weekend (Saturday or Sunday)
    bool isWeekEnd(short dayOrderInWeek) { 
        return dayOrderInWeek == 0 || dayOrderInWeek == 6; 
    } 

    // Check if the day is a business day (not Saturday or Sunday)
    bool isBusinessDay(short dayOrderInWeek) { 
        return !isWeekEnd(dayOrderInWeek); 
    } 

    // Days remaining until the end of the week (Saturday)
    short daysUntilTheEndOfWeek(short dayOrderInWeek) { 
        return 6 - dayOrderInWeek; 
    } 

    short daysUntilTheEndOfMonth(stDate Date) { 
        return getDaysInMonth(Date.Year, Date.Month) - Date.Day; 
    } 

    short daysUntilTheEndOfYear(stDate Date) { 
        return getDaysInYear(Date.Year) - countDaysFromYearStart(Date.Day, Date.Month, Date.Year); 
    }


    // ==== Date Functions ====

    // Input / Output
    stDate readFullDate() {
        stDate Date;
        Date.Day   = io_utils::readPositiveNumber("\nPlease enter a day: ");
        Date.Month = io_utils::readPositiveNumber("Please enter a month: "); 
        Date.Year  = io_utils::readPositiveNumber("Please enter a year: "); 
        return Date;
    }

    void printDate(const stDate& Date, string message) {
    if (!message.empty())
        cout << message;
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

    // Conversion
    stDate dateAddDays(short days, short year) {
        stDate Date;
        short remainingDays = days;
        short monthDays = 0;
        Date.Year = year;
        Date.Month = 1;

        while(true) {
            monthDays = getDaysInMonth(Date.Year, Date.Month);
            if(remainingDays > monthDays) {
                remainingDays -= monthDays;
                Date.Month++;
            } else {
                Date.Day = remainingDays;
                break;
            }
        }
        return Date;
    }

    stDate convertDaysToDate(short daysOrderInYear, short year) {
        return dateAddDays(daysOrderInYear, year);
    }

    // ==== Increment ====
    stDate increaseDateByOneDay(stDate Date) {
        if (isLastDayInMonth(Date) && isLastMonthInYear(Date.Month)) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else if (isLastDayInMonth(Date)) {
            Date.Day = 1;
            Date.Month++;
        }
        else {
            Date.Day++;
        }
        return Date;
    }

    stDate increaseDateByXDays(stDate Date, short days) {
        for (short i = 0; i < days; i++) {
            Date = increaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate increaseDateByOneWeek(stDate Date) {
        return increaseDateByXDays(Date, 7);
    }

    stDate increaseDateByXWeeks(stDate Date, short weeks) {
        for (short i = 0; i < weeks; i++) {
            Date = increaseDateByOneWeek(Date);
        }
        return Date;
    }

    stDate increaseDateByOneMonth(stDate Date) {
        if (Date.Month == 12) {
            Date.Month = 1;
            Date.Year++;
        } else {
            Date.Month++;
        }

        short numberOfDaysInMonth = getDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > numberOfDaysInMonth) {
            Date.Day = numberOfDaysInMonth;
        }
        return Date;
    }

    stDate increaseDateByXMonths(stDate Date, short months) {
        for (short i = 0; i < months; i++) {
            Date = increaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate increaseDateByOneYear(stDate Date) {
        Date.Year++;
        return Date;
    }

    stDate increaseDateByXYears(stDate Date, short years) {
        for (short i = 0; i < years; i++) {
            Date = increaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate increaseDateByXYearsFaster(stDate Date, short years) {
        Date.Year += years;
        return Date;
    }

    stDate increaseDateByOneDecade(stDate Date) {
        Date.Year += 10;
        return Date;
    }

    stDate increaseDateByXDecades(stDate Date, short decades) {
        for (short i = 0; i < decades * 10; i++) {
            Date = increaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate increaseDateByDecadesFaster(stDate Date, short decades) {
        Date.Year += decades * 10;
        return Date;
    }

    stDate increaseDateByOneCentury(stDate Date) {
        Date.Year += 100;
        return Date;
    }

    stDate increaseDateByOneMillennium(stDate Date) {
        Date.Year += 1000;
        return Date;
    }

    // ==== Decrement ====
    stDate decreaseDateByOneDay(stDate Date) {
        if (Date.Day == 1) {
            if (Date.Month == 1) {
                Date.Month = 12;
                Date.Year--;
            } else {
                Date.Month--;
            }
            Date.Day = getDaysInMonth(Date.Year, Date.Month);
        } else {
            Date.Day--;
        }

        return Date;
    }

    stDate decreaseDateByXDays(stDate Date, short days) {
        for (short i = 0; i < days; i++) {
            Date = decreaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate decreaseDateByOneWeek(stDate Date) {
        return decreaseDateByXDays(Date, 7);
    }

    stDate decreaseDateByXWeeks(stDate Date, short weeks) {
        for (short i = 0; i < weeks; i++) {
            Date = decreaseDateByOneWeek(Date);
        }
        return Date;
    }

    stDate decreaseDateByOneMonth(stDate Date) {
        if (Date.Month == 1) {
            Date.Month = 12;
            Date.Year--;
        } else {
            Date.Month--;
        }

        short numberOfDaysInMonth = getDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > numberOfDaysInMonth) {
            Date.Day = numberOfDaysInMonth;
        }
        return Date;
    }

    stDate decreaseDateByXMonths(stDate Date, short months) {
        for (short i = 0; i < months; i++) {
            Date = decreaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate decreaseDateByOneYear(stDate Date) {
        Date.Year--;
        return Date;
    }

    stDate decreaseDateByXYears(stDate Date, short years) {
        for (short i = 0; i < years; i++) {
            Date = decreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate decreaseDateByXYearsFaster(stDate Date, short years) {
        Date.Year -= years;
        return Date;
    }

    stDate decreaseDateByOneDecade(stDate Date) {
        Date.Year -= 10;
        return Date;
    }

    stDate decreaseDateByXDecades(stDate Date, short decades) {
        for (short i = 0; i < decades * 10; i++) {
            Date = decreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate decreaseDateByDecadesFaster(stDate Date, short decades) {
        Date.Year -= decades * 10;
        return Date;
    }

    stDate decreaseDateByOneCentury(stDate Date) {
        Date.Year -= 100;
        return Date;
    }

    stDate decreaseDateByOneMillennium(stDate Date) {
        Date.Year -= 1000;
        return Date;
    }


    // Comparison
    bool isDate1BeforeDate2(const stDate& Date1, const stDate& Date2) {
        if (Date1.Year != Date2.Year) return Date1.Year < Date2.Year;
        if (Date1.Month != Date2.Month) return Date1.Month < Date2.Month;
        return Date1.Day < Date2.Day;
    }

    bool isDate1EqualDate2(const stDate& Date1, const stDate& Date2) {
        return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
    }

    // Helpers
    bool isLastDayInMonth(stDate& Date) {
        return (Date.Day == getDaysInMonth(Date.Year, Date.Month));
    }

    bool isLastMonthInYear(short month) {
        return month == 12;
    }

    short countDaysFromYearStart(short day, short month, short year) {
        short totalDays = 0;
        for(short i = 1; i < month; i++) {
            totalDays += getDaysInMonth(year, i);
        }
        totalDays += day;
        return totalDays;
    }

    void swapDates(stDate& Date1, stDate& Date2){
        stDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    // Difference
    int getDifferenceInDays(stDate Date1, stDate Date2, bool includeEndDay) {
        int days = 0;
        short swapFlagValue = 1;

        if (!isDate1BeforeDate2(Date1, Date2)) {
            swapDates(Date1, Date2);
            swapFlagValue = -1;
        }

        while (Date1.Year != Date2.Year) {
            days += getDaysInYear(Date2.Year);
            Date2.Year--;
        }

        while (Date1.Month != Date2.Month) {
            days += getDaysInMonth(Date2.Year, Date2.Month);
            Date2.Month--;
        }

        while (Date1.Day != Date2.Day) {
            days++;
            Date2.Day--;
        } 

        return includeEndDay ? ++days * swapFlagValue : days * swapFlagValue;
    }

}