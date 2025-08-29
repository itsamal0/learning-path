#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
using namespace std;

/*
==================================================
   Problem: Write a program to fill a matrix with ordered numbers.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

// Fill the matrix with ordered numbers
void fillMatrixWithOrderedNumbers(vector<vector<int>>& vMatrix, short rows, short cols) {
    short counter = 1;
    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            vMatrix[i][j] = counter++;
        }
    }
}

// Print the matrix in a formatted way
void printMatrix(const vector<vector<int>>& vMatrix, short rows, short cols) {
    cout << "\nThe following is a " << rows << "x" << cols << " ordered matrix:\n";
    for(const vector<int>& row : vMatrix) {
        for(const int& number : row) {
            // setw(2) makes numbers take at least 2 spaces
            // setfill('0') puts a zero in front of 1-digit numbers (example: 5 -> 05)
            cout << setfill('0') << setw(2) << number << " ";
        }
        cout << endl;
    }
}

int main()
{
    short rows = 3, cols = 3;

    // Create a 2D vector (matrix) initialized with zeros
    vector<vector<int>> vMatrix(rows, vector<int>(cols, 0));

    fillMatrixWithOrderedNumbers(vMatrix, rows, cols);

    printMatrix(vMatrix, rows, cols);

    return 0;
}