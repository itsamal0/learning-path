#include <iostream>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to print all vowels
            in a string.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

// Check if a character is a vowel
bool isVowel(char letter)
{
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

// Print all vowels in a string
void printVowelsLetters(string str)
{
    cout << "\nVowels in string are : ";
    for (int i = 0; i < str.length(); i++)
    {
        if (isVowel(str[i]))
        {
            cout << str[i] << "   ";
        }
    }
}

int main()
{
    // Read string from user using io_utils
    string str = io_utils::readString("Please enter your string ? ");
    printVowelsLetters(str);

    // Wait for user input before closing the console
    system("pause>0");
}