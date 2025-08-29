#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
using namespace std;

/*
==================================================
   Problem: Write a program to check if the matrix is identity or not.
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

bool isIdentityMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == j && vMatrix[i][j] != 1) return false;
            if(i != j && vMatrix[i][j] != 0) return false;
        }
    }
    return true;
}

int main()
{
    // Create a 2D vector (matrix) initialized with zeros
    Vec2DInt vMatrix = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    short rows = vMatrix.size();
    short cols = vMatrix[0].size();

    cout << "\nMatrix:\n";
    printMatrix(vMatrix, rows, cols);

    if(isIdentityMatrix(vMatrix, rows, cols))
        cout << "\nYES: Matrix is identity.";
    else
        cout << "\nNo: Matrix is NOT identity.";

    return 0;
}