#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
using namespace std;

/*
==================================================
   Problem: Write a program to fill a matrix with random numbers,
            print it, then print the middle row and the middle column.
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

void printMiddleRowOfMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    for(int i = 0; i < cols; i++) {
        cout << setfill('0') << setw(2) << vMatrix[rows / 2][i] << " ";
    }
}

void printMiddleColOfMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    for(int i = 0; i < rows; i++) {
        cout << setfill('0') << setw(2) << vMatrix[i][cols / 2] << " ";
    }
}

int main()
{
    // Seed the random generator so numbers change every run
    srand((unsigned)time(NULL));

    short rows = 3, cols = 3;

    // Create a 2D vector (matrix) initialized with zeros
    Vec2DInt vMatrix(rows, vector<int>(cols, 0));

    fillMatrixWithRandomNumbers(vMatrix, rows, cols);
    cout << "\nMatrix:\n";
    printMatrix(vMatrix, rows, cols);

    cout << "\n\nMiddle row of the matrix is:\n";
    printMiddleRowOfMatrix(vMatrix, rows, cols);

    cout << "\n\nMiddle col of the matrix is:\n";
    printMiddleColOfMatrix(vMatrix, rows, cols);

    return 0;
}