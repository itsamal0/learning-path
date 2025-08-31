#include <iostream>
#include <string>
#include <vector>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Join words from a vector into one string 
            separated by a chosen delimiter.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Example vector of strings
    vector<string> vString = { "Kiyomi", "Dev" };

    cout << "\nJoined string: " 
         << helperFunctions::joinString(vString, "#");

    // Wait for user input before closing the console
    system("pause>0");
}
