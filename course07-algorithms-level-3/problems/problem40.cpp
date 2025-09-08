#include <iostream>
#include <string>
#include <vector>
#include "../helpers/string_utils.h"
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

    // Join vector using string_utils (overloaded function)
    cout << "\nVector after join:\n" 
         << string_utils::joinString(vString, "#");

    // Join array using string_utils (overloaded function)
    cout << "\nArray after join:\n" 
         << string_utils::joinString(strArr, 2, "#");

    // Wait for user input before closing
    system("pause>0");
}