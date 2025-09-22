#pragma once
#include <string>

struct stDate {
    short Day;
    short Month;
    short Year;
};

namespace date_utils {

    // ==== Year Functions ====
    bool isLeapYear(int year);
    short getDaysInYear(int year);
    short getHoursInYear(int year);
    int getMinutesInYear(int year);
    int getSecondsInYear(int year);

    // ==== Month Functions ====
    short getDaysInMonth(short year, short month);
    short getHoursInMonth(short year, short month);
    int getMinutesInMonth(short year, short month);
    int getSecondsInMonth(short year, short month);
    std::string getMonthShortName(short month);

    // ==== Week Functions ====
    short getDayOfWeekOrder(short year, short month, short day);
    std::string getDayShortName(short day);

    // ==== Date Functions ====

    // Input / Output
    stDate readFullDate();

    // Conversion
    stDate dateAddDays(short days, short year);
    stDate convertDaysToDate(short daysOrderInYear, short year);

    // Increment
    stDate increaseDateByOneDay(stDate& Date);

    // Comparison
    bool isDate1BeforeDate2(const stDate& Date1, const stDate& Date2);
    bool isDate1EqualDate2(const stDate& Date1, const stDate& Date2);

    // Helpers
    bool isLastDayInMonth(stDate& Date);
    bool isLastMonthInYear(short month);
    short countDaysFromYearStart(short day, short month, short year);
    void swapDates(stDate& Date1, stDate& Date2);

    // Difference
    int getDifferenceInDays(stDate Date1, stDate Date2, bool includeEndDay = false);

}
