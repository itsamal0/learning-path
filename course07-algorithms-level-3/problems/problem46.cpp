#include <iostream>
#include <string>
#include <vector>
#include "../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Convert a client record line into a 
            struct and print the client details.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

struct stClient {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

// Convert a single line string to a client struct
stClient convertLineToRecord(string str, string separator = "#//#") {
    stClient newClient;
    vector<string> vString = string_utils::splitString(str, separator);

    newClient.accountNumber   = vString[0];
    newClient.pinCode         = vString[1];
    newClient.name            = vString[2];
    newClient.phone           = vString[3];
    newClient.accountBalance  = stod(vString[4]);

    return newClient;
}

// Print the client record in a readable format
void printClientRecord(stClient client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount Number   : " << client.accountNumber;
    cout << "\nPin Code         : " << client.pinCode;
    cout << "\nName             : " << client.name;
    cout << "\nPhone            : " << client.phone;
    cout << "\nAccount Balance  : " << client.accountBalance;
}

int main() {
    string stLine = "A150#//#1234#//#Kiyomi Dev#//#079999#//#5270.000000";

    cout << "\nLine Record is:\n" << stLine << endl;

    stClient client = convertLineToRecord(stLine);
    printClientRecord(client);

    // Wait for user input before closing
    system("pause>0");
}