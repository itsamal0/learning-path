#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
using namespace std;

/*
==================================================
   Problem: Write a program to print the minimum and maximum numbers in the matrix.
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

// Find and return the minimum number in the matrix
int minNumberInMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    int minNumber = vMatrix[0][0];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(vMatrix[i][j] < minNumber){
                minNumber = vMatrix[i][j];
            }
        }
    }
    
    return minNumber;
}

// Find and return the maximum number in the matrix
int maxNumberInMatrix(const Vec2DInt& vMatrix, short rows, short cols) {
    int maxNumber = vMatrix[0][0];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(vMatrix[i][j] > maxNumber){
                maxNumber = vMatrix[i][j];
            }
        }
    }
    
    return maxNumber;
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

    cout << "\nMin number is: " << minNumberInMatrix(vMatrix, rows, cols);
    cout << "\nMax number is: " << maxNumberInMatrix(vMatrix, rows, cols);
    
    return 0;
}