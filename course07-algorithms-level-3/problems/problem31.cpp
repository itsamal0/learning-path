#include <iostream>
#include "../../helpers/io_utils.h"
#include "../../helpers/char_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to count how many times
            a specific character appears in a string,
            with optional case-insensitive counting.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

short countLetter(string str, char letter, bool matchCase = true)
{
    short counter = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (matchCase)
        {
            if (str[i] == letter)
            {
                counter++;
            }
        }
        else
        {
            if (tolower(str[i]) == tolower(letter))
            {
                counter++;
            }
        }
    }

    return counter;
}

int main()
{
    string str = io_utils::readString("Please enter your string ?");
    char letter = io_utils::readLetter("Please enter a character ?");

    cout << "\nLetter '" << letter << "' count = " << countLetter(str, letter);
    cout << "\nLetter '" << letter << "' or '"
         << char_utils::invertLetterCase(letter)
         << "' = " << countLetter(str, letter, false);

    system("pause>0");
}