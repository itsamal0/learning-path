#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
using namespace std;

/*
==================================================
   Problem: Write a program to check the matrix is sparse or not.
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

// Check if the matrix is sparse or not
bool isSparseMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    int zeros = 0;

    for(const vector<int>& row : vMatrix) {
        for(const int& number : row) {
            if(number == 0) zeros++;
        }
    }

    int totalElements = rows * cols;
    return zeros > totalElements / 2;
}

int main()
{
    // Create a 2D vector (matrix) initialized with zeros
    Vec2DInt vMatrix = {
        {1,0,5},
        {3,0,0},
        {0,1,0}
    };

    short rows = vMatrix.size();
    short cols = vMatrix[0].size();

    cout << "\nMatrix:\n";
    printMatrix(vMatrix, rows, cols);

    if (isSparseMatrix(vMatrix, rows, cols))
        cout <<"\nYes: It is Sparse\n";
    else
        cout <<"\nNo: It's NOT Sparse\n";

    return 0;
}