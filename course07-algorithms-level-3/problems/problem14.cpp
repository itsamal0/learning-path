#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
using namespace std;

/*
==================================================
   Problem: Write a program to check if the matrix is scalar or not.
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

// Check if the matrix is scalar or not
bool isScalarMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    int scalarValue = vMatrix[0][0];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == j && vMatrix[i][j] != scalarValue) return false;
            if(i != j && vMatrix[i][j] != 0) return false;
        }
    }

    return true;
}

int main()
{
    // Create a 2D vector (matrix) initialized with zeros
    Vec2DInt vMatrix = {
        {5,0,0},
        {0,5,0},
        {0,0,5}
    };

    short rows = vMatrix.size();
    short cols = vMatrix[0].size();

    cout << "\nMatrix:\n";
    printMatrix(vMatrix, rows, cols);

    if(isScalarMatrix(vMatrix, rows, cols))
        cout << "\nYES: Matrix is scalar.";
    else
        cout << "\nNo: Matrix is NOT scalar.";

    return 0;
}
