#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
using namespace std;

/*
==================================================
   Problem: Write a program to fill a matrix with ordered numbers
            and print it, then transpose matrix and print it.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

// Alias for 2D vector of integers
using Vec2DInt = vector<vector<int>>;

// Fill the matrix with ordered numbers
void fillMatrixWithOrderedNumbers(Vec2DInt& vMatrix, short rows, short cols) {
    short counter = 1;
    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            vMatrix[i][j] = counter++;
        }
    }
}

// Transpose the matrix
Vec2DInt transposeMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    Vec2DInt vTransposedMatrix(cols, vector<int>(rows,0));

    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            vTransposedMatrix[j][i] = vMatrix[i][j];
        }
    }
    return vTransposedMatrix;
}

// Print the matrix in a formatted way
void printMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            cout << setfill('0') << setw(2) << vMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    short rows = 3, cols = 3;

    // Create a 2D vector (matrix) initialized with zeros
    Vec2DInt vMatrix(rows, vector<int>(cols, 0));

    fillMatrixWithOrderedNumbers(vMatrix, rows, cols);

    cout << "\nThe following is a " << rows << "x" << cols << " ordered matrix:\n";
    printMatrix(vMatrix, rows, cols);

    Vec2DInt vTransposedMatrix = transposeMatrix(vMatrix, rows, cols);

    cout << "\n\nThe following is the transposed matrix:\n";
    printMatrix(vTransposedMatrix, cols, rows);

    return 0;
}