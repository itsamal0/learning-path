#include <iostream>
#include <string>
#include <vector>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem: Write a program to read bank client data record
            and convert it to one line.
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

// Convert a client struct to a single line string with separator
string convertRecordToLine(stClient client, string separator = "#//#") {
    string stClientRecord = "";
    
    stClientRecord += client.accountNumber + separator;
    stClientRecord += client.pinCode + separator;
    stClientRecord += client.name + separator;
    stClientRecord += client.phone + separator;
    stClientRecord += to_string(client.accountBalance);
    
    return stClientRecord;
}

// Read new client data from user
stClient readNewClient() {
    stClient newClient;

    newClient.accountNumber   = helperFunctions::readString("\nEnter account number: ");
    newClient.pinCode         = helperFunctions::readString("\nEnter pin code: ");
    newClient.name            = helperFunctions::readString("\nEnter name: ");
    newClient.phone           = helperFunctions::readString("\nEnter phone number: ");
    newClient.accountBalance  = helperFunctions::readPositiveNumber("\nEnter account balance: ");

    return newClient;
}

int main() {
    cout << "\nPlease enter client data:\n";

    // Read client info
    stClient client = readNewClient();

    // Show client record line
    cout << "\nClient record for saving is:\n" 
         << convertRecordToLine(client) << endl;

    // Wait for user input before closing
    system("pause>0");
}