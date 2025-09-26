#pragma once
#include <string>

enum enCompareTwoDates { BEFORE = -1, EQUAL = 0, AFTER = 1 };

struct stDate {
    short Day;
    short Month;
    short Year;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
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
    short getDayOfWeekOrder(stDate Date);
    std::string getDayShortName(short day);

    // ==== Week / Day Utilities ====
    bool isEndOfWeek(short dayOrderInWeek);
    bool isWeekEnd(short dayOrderInWeek);
    bool isBusinessDay(short dayOrderInWeek);
    short daysUntilTheEndOfWeek(short dayOrderInWeek);
    short daysUntilTheEndOfMonth(stDate Date);
    short daysUntilTheEndOfYear(stDate Date);

    // ==== Date Functions ====

    // Input / Output
    stDate readFullDate();
    void printDate(const stDate& Date, std::string message);

    // Conversion
    stDate dateAddDays(short days, short year);
    stDate convertDaysToDate(short daysOrderInYear, short year);

    // Increment
    stDate increaseDateByOneDay(stDate Date);
    stDate increaseDateByXDays(stDate Date, short days = 10);
    stDate increaseDateByOneWeek(stDate Date);
    stDate increaseDateByXWeeks(stDate Date, short weeks = 10);
    stDate increaseDateByOneMonth(stDate Date);
    stDate increaseDateByXMonths(stDate Date, short months = 5);
    stDate increaseDateByOneYear(stDate Date);
    stDate increaseDateByXYears(stDate Date, short years = 10);
    stDate increaseDateByXYearsFaster(stDate Date, short years = 10);
    stDate increaseDateByOneDecade(stDate Date);
    stDate increaseDateByXDecades(stDate Date, short decade = 10);
    stDate increaseDateByDecadesFaster(stDate Date, short decade = 10);
    stDate increaseDateByOneCentury(stDate Date);
    stDate increaseDateByOneMillennium(stDate Date);

    // Decrement
    stDate decreaseDateByOneDay(stDate Date);
    stDate decreaseDateByXDays(stDate Date, short days = 10);
    stDate decreaseDateByOneWeek(stDate Date);
    stDate decreaseDateByXWeeks(stDate Date, short weeks = 10);
    stDate decreaseDateByOneMonth(stDate Date);
    stDate decreaseDateByXMonths(stDate Date, short months = 5);
    stDate decreaseDateByOneYear(stDate Date);
    stDate decreaseDateByXYears(stDate Date, short years = 10);
    stDate decreaseDateByXYearsFaster(stDate Date, short years = 10);
    stDate decreaseDateByOneDecade(stDate Date);
    stDate decreaseDateByXDecades(stDate Date, short decade = 10);
    stDate decreaseDateByDecadesFaster(stDate Date, short decade = 10);
    stDate decreaseDateByOneCentury(stDate Date);
    stDate decreaseDateByOneMillennium(stDate Date);

    // Comparison
    bool isDate1BeforeDate2(const stDate& Date1, const stDate& Date2);
    bool isDate1EqualDate2(const stDate& Date1, const stDate& Date2);
    bool isDate1AfterDate2(const stDate& Date1, const stDate& Date2);
    enCompareTwoDates compareTwoDates(stDate Date1, stDate Date2);

    // ==== Period / Date Ranges ====
    short periodLengthInDays(stPeriod Period1, bool includeEndDay = false);
    bool isOverlapPeriods(stPeriod Period1, stPeriod Period2);
    bool isDateWithinPeriod(stPeriod Period, stDate Date);

    // Helpers
    bool isLastDayInMonth(stDate& Date);
    bool isLastMonthInYear(short month);
    short countDaysFromYearStart(short day, short month, short year);
    void swapDates(stDate& Date1, stDate& Date2);

    // Difference
    int getDifferenceInDays(stDate Date1, stDate Date2, bool includeEndDay = false);

}