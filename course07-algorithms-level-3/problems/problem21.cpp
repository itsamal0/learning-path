#include<iostream>
using namespace std;

/*
==================================================
   Problem: Write a program to print Fibonacci series of 10.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

void printFibonacciSeries(short n){
    short prev1 = 1, prev2 = 0;
    short fiboNumber = 0;
    cout << "1  ";
    for(int i = 2; i <= n; ++i){
        fiboNumber = prev1 + prev2;
        cout << fiboNumber << "  ";
        prev2 = prev1;   
        prev1 = fiboNumber;
    }
}

int main()
{
    printFibonacciSeries(10);
    return 0;
}