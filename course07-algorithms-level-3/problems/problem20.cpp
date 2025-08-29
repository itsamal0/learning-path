#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
using namespace std;

/*
==================================================
   Problem: Write a program to check if the matrix is palindrome or not.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

// Alias for 2D vector of integers
using Vec2DInt = vector<vector<int>>;

// Print the matrix in a formatted way
void printMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    for(const vector<int>& row : vMatrix) {
        for(const int& number : row) {
            // setw(2) makes numbers take at least 2 spaces
            // setfill('0') puts a zero in front of 1-digit numbers (example: 5 -> 05)
            cout << setfill('0') << setw(2) << number << " ";
        }
        cout << endl;
    }
}

// Check if the matrix is palindrome or not
bool isPalindromeMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols / 2; j++) {
            if (vMatrix[i][j] != vMatrix[i][cols - 1 - j]){
                return false;
            }
        }
    }

    return true;
}

int main()
{
    Vec2DInt vMatrix = { {1,2,1},{4,2,4},{2,1,2} };

    cout << "\nMatrix:\n";
    printMatrix(vMatrix, 3, 3);

    if (isPalindromeMatrix(vMatrix, 3, 3))
        cout << "\nYes: Matrix is Palindrome\n"; 
    else  
        cout << "\nNo: Matrix is NOT Palindrome\n"; 

    return 0;
}