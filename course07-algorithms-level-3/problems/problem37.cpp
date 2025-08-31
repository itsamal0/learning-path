#include <iostream>
#include <vector>
#include "../helpers/helperFunctions.h"
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
    // Read string and delimiter from user using helperFunctions
    string str = helperFunctions::readString("Please enter your string ?");
    string delimiter = helperFunctions::readString("Please enter a delimiter ?");

    // Split string using helperFunctions
    vector<string> vString = helperFunctions::splitString(str, delimiter);

    cout << "\nTokens = " << vString.size() << endl;
    printVector(vString);

    // Wait for user input before closing the console
    system("pause>0");
}
