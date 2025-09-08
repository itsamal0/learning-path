#include <iostream>
#include <vector>
#include "../helpers/io_utils.h"
#include "../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Split a string into tokens based on a 
            given delimiter and print each token.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Print vector<string> elements line by line
void printVector(vector<string>& strArr) {
    for (string& word : strArr) {
        cout << word << endl;
    }
}

int main() {
    // Read string and delimiter from user using io_utils
    string str = io_utils::readString("Please enter your string ?");
    string delimiter = io_utils::readString("Please enter a delimiter ?");

    // Split string using string_utils
    vector<string> vString = string_utils::splitString(str, delimiter);

    cout << "\nTokens = " << vString.size() << endl;
    printVector(vString);

    // Wait for user input before closing the console
    system("pause>0");
}