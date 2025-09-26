#include <iostream>
#include <vector>
#include "../../helpers/date_utils.h"
#include "../../helpers/io_utils.h"
#include "../../helpers/string_utils.h"
using namespace std;


string replaceWordInString(string str, string target, string replacement) {
    size_t pos = 0;
    while ((pos = str.find(target, pos)) != string::npos) {
        str.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
    return str;
}

stDate stringToDate(string strDate) {
    stDate Date;
    vector<string> vDate = string_utils::splitString(strDate, "/");

    Date.Day   = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year  = stoi(vDate[2]);

    return Date;
}

string formateDate(stDate Date, string dateFormat = "dd/mm/yyyy") {
    string formattedDateString = dateFormat;

    formattedDateString = replaceWordInString(formattedDateString, "dd", to_string(Date.Day));
    formattedDateString = replaceWordInString(formattedDateString, "mm", to_string(Date.Month));
    formattedDateString = replaceWordInString(formattedDateString, "yyyy", to_string(Date.Year));

    return formattedDateString;
}

int main() {
    string strDate = io_utils::readString("\nEnter a date dd/mm/yyyy: ");
    stDate Date = stringToDate(strDate);

    cout << "\n" << formateDate(Date) << "\n";
    cout << "\n" << formateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << formateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << formateDate(Date, "mm-dd-yyyy") << "\n"; 
    cout << "\n" << formateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << formateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");

    return 0;
}