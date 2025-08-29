#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
using namespace std;

/*
==================================================
   Problem: Create two matrices, fill each with random numbers,
            print them, then multiply them into a 3rd matrix and print it.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

// Alias for 2D vector of integers
using Vec2DInt = vector<vector<int>>;

// Generate a random number between "from" and "to"
int generateRandomNumber(int from, int to) {
    int randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}

// Fill the matrix with random numbers
void fillMatrixWithRandomNumbers(Vec2DInt& vMatrix, short rows, short cols) {
    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            vMatrix[i][j] = generateRandomNumber(1, 10);
        }
    }
}

Vec2DInt multiplyMatrix(const Vec2DInt& vMatrix, const Vec2DInt& vMatrix2) {
    short rows = vMatrix.size();
    short cols = vMatrix[0].size();
    Vec2DInt vMatrixResults(rows, vector<int>(cols, 0));

    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            vMatrixResults[i][j] = vMatrix[i][j] * vMatrix2[i][j];
        }
    }
    return vMatrixResults;
}

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

int main()
{
    // Seed the random generator so numbers change every run
    srand((unsigned)time(NULL));

    short rows = 3, cols = 3;

    // Create a 2D vector (matrix) initialized with zeros
    Vec2DInt vMatrix(rows, vector<int>(cols, 0));
    Vec2DInt vMatrix2(rows, vector<int>(cols, 0));

    fillMatrixWithRandomNumbers(vMatrix, rows, cols);
    cout << "\nMatrix1:\n";
    printMatrix(vMatrix, rows, cols);

    fillMatrixWithRandomNumbers(vMatrix2, rows, cols);
    cout << "\nMatrix2:\n";
    printMatrix(vMatrix2, rows, cols);

    Vec2DInt vMatrixResults = multiplyMatrix(vMatrix, vMatrix2);
    cout << "\nResults:\n"; 
    printMatrix(vMatrixResults, rows, cols);

    return 0;
}