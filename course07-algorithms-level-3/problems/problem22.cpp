#include<iostream>
using namespace std;

/*
==================================================
   Problem: Write a program to print Fibonacci series using recursion.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

void printFibonacciUsingRecursion(short n, short prev1, short prev2) {
    short fiboNumber = 0;

    if(n > 0) {
        fiboNumber = prev1 + prev2;
        prev2 = prev1;
        prev1 = fiboNumber;
        cout << fiboNumber << "  ";
        printFibonacciUsingRecursion(n - 1, prev1, prev2);
    }
}

int main()
{
    printFibonacciUsingRecursion(10, 0, 1);
    return 0;
}