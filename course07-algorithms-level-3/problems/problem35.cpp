#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print each word
            in a string on a separate line.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Print each word in a string
void printEachWordInString(string str)
{
    cout << "\nYour string words are: " << endl;
    string delim = " ";
    short pos = 0;
    string word = "";

    while ((pos = str.find(delim)) != string::npos)
    {
        word = str.substr(0, pos);
        if (word != "")
        {
            cout << word << endl;
        }
        str.erase(0, pos + delim.length());
    }

    if (str != "")
    {
        cout << str << endl;
    }
}

int main()
{
    // Read string from user using io_utils
    string str = io_utils::readString("Please enter your string ?");
    printEachWordInString(str);

    // Wait for user input before closing the console
    system("pause>0");
}