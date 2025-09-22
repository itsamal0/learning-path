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