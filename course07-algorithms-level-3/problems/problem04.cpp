#include <iostream>
#include <vector>
#include <iomanip>  // for setw and setfill
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
using namespace std;

/*
==================================================
   Problem: Write a program to fill a matrix with random numbers, 
            then print each col sum.
   From   : Programming Advices – Course 7
   Date   : 2025-08-29
==================================================
*/

// Generate a random number between "from" and "to"
int generateRandomNumber(int from, int to) {
    int randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}

// Fill the matrix with random numbers
void fillMatrixWithRandomNumbers(vector<vector<int>>& vMatrix, short rows, short cols) {
    for(short i = 0; i < rows; i++) {
        for(short j = 0; j < cols; j++) {
            vMatrix[i][j] = generateRandomNumber(1, 10);
        }
    }
}

// Print the matrix in a formatted way
void printMatrix(const vector<vector<int>>& vMatrix, short rows, short cols) {
    cout << "The following is a " << rows << "x" << cols << " random matrix:\n";
    for(const vector<int>& row : vMatrix) {
        for(const int& number : row) {
            // setw(2) makes numbers take at least 2 spaces
            // setfill('0') puts a zero in front of 1-digit numbers (example: 5 -> 05)
            cout << setfill('0') << setw(2) << number << " ";
        }
        cout << endl;
    }
}

// Calculate the sum of all cols in the matrix
vector<int> calculateAllColSums(const vector<vector<int>>& vMatrix) {
    vector<int> colSums;
    for(int i = 0; i < vMatrix[0].size(); i++) {
        int sum = 0;
        
        for(int j = 0; j < vMatrix.size(); j++) {
            sum += vMatrix[j][i];
        }
        colSums.push_back(sum);
    }
    return colSums;
}

// Prints the sum of each col in the matrix
void printColSums(const vector<int>& colSums) {
    cout << "\nThe following are the sum of each col in the matrix:\n";
    for (int i = 0; i < colSums.size(); i++) {
        cout << "Col " << i + 1 << " sum = " << colSums[i] << endl;
    }
}

int main()
{
    // Seed the random generator so numbers change every run
    srand((unsigned)time(NULL));

    short rows = 5, cols = 3;

    // Create a 2D vector (matrix) initialized with zeros
    vector<vector<int>> vMatrix(rows, vector<int>(cols, 0));

    fillMatrixWithRandomNumbers(vMatrix, rows, cols);

    printMatrix(vMatrix, rows, cols);

    vector<int> vSums = calculateAllColSums(vMatrix);

    printColSums(vSums);

    return 0;
}