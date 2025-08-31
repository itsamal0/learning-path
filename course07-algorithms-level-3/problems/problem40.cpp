#include <iostream>
#include <string>
#include <vector>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Demonstrate joining elements of a 
            vector or array into a single string
            using a specified delimiter using function overloading.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

int main() {
    // Example vector and array
    vector<string> vString = { "Kiyomi", "Dev" };
    string strArr[] = { "Kiyomi", "Dev" };

    // Join vector using helperFunctions (overloaded function)
    cout << "\nVector after join:\n" 
         << helperFunctions::joinString(vString, "#");

    // Join array using helperFunctions (overloaded function)
    cout << "\nArray after join:\n" 
         << helperFunctions::joinString(strArr, 2, "#");

    // Wait for user input before closing
    system("pause>0");
}