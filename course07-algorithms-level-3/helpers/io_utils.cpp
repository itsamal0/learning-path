#include "io_utils.h"
#include <iostream>
using namespace std;

namespace io_utils {

    string readString(const string& message) {
        string str;
        cout << message;
        getline(cin, str);
        return str;
    }

    int readPositiveNumber(const string& message) {
        int num;
        bool validInput = false;
        do {
            cout << message;
            cin >> num;
            if (cin.fail() || num <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a positive number.\n";
            } else {
                validInput = true;
            }
        } while (!validInput);
        return num;
    }

    char readLetter(const string& message) {
        char c;
        cout << message;
        cin >> c;
        return c;
    }

}