#include <iostream>
#include <string>
#include "../../helpers/io_utils.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read a number,
            and print the text of that number.
   From   : Programming Advices – Course 8
   Date   : 2025-09-17
==================================================
*/

// Convert a single digit [0–9] to text
string digitToText(int n)
{
  switch (n)
  {
  case 0: return "Zero";
  case 1: return "One";
  case 2: return "Two";
  case 3: return "Three";
  case 4: return "Four";
  case 5: return "Five";
  case 6: return "Six";
  case 7: return "Seven";
  case 8: return "Eight";
  case 9: return "Nine";
  default: return "";
  }
}

// Convert numbers from 10–19 to text
string numberTeens(int n)
{
  switch (n)
  {
  case 10: return "Ten";
  case 11: return "Eleven";
  case 12: return "Twelve";
  case 13: return "Thirteen";
  case 14: return "Fourteen";
  case 15: return "Fifteen";
  case 16: return "Sixteen";
  case 17: return "Seventeen";
  case 18: return "Eighteen";
  case 19: return "Nineteen";
  default: return "";
  }
}

// Convert tens multiples [20, 30, 40, ...]
string numberToTens(int n)
{
  switch (n)
  {
  case 2: return "Twenty";
  case 3: return "Thirty";
  case 4: return "Forty";
  case 5: return "Fifty";
  case 6: return "Sixty";
  case 7: return "Seventy";
  case 8: return "Eighty";
  case 9: return "Ninety";
  default: return "";
  }
}

// Convert a full integer number into text
string numberToText(int n) {

  if (n == 0) return "Zero";

  string result = "";

  if (n >= 1000000000) {
    result += numberToText(n / 1000000000) + " Billion";
    n %= 1000000000;
    if (n > 0) result += " ";
  }

  if (n >= 1000000) {
    result += numberToText(n / 1000000) + " Million";
    n %= 1000000;
    if (n > 0) result += " ";
  }

  if (n >= 1000) {
    result += numberToText(n / 1000) + " Thousand";
    n %= 1000;
    if (n > 0) result += " ";
  }

  if (n >= 100) {
    result += digitToText(n / 100) + " Hundred";
    n %= 100;
    if (n > 0) result += " ";
  }

  if (n >= 20) {
    result += numberToTens(n / 10);
    n %= 10;
    if (n > 0) result += " " + digitToText(n);
  }
  else if (n >= 10) {
    result += numberTeens(n);
  }
  else if (n > 0) {
    result += digitToText(n);
  }

  return result;
}

int main() {
  int n;

  n = io_utils::readPositiveNumber("Enter a number : ");

  cout << numberToText(n) << endl;

  return 0;
}