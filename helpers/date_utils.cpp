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

    string getDayShortName(short day) {
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return days[day];
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

    // Increment
    stDate increaseDateByOneDay(stDate& Date) {
        if (isLastDayInMonth(Date) && isLastMonthInYear(Date.Month)) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
            return Date;
        }
        if (isLastDayInMonth(Date)) {
        Date.Day = 1;
        Date.Month++;
        } else {
            Date.Day++;
        }
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