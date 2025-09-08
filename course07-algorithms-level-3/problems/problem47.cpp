#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "../helpers/io_utils.h"
using namespace std;


/*
==================================================
   Problem: Add new bank clients to a file.
            Each client is stored as a single line record.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

const string clientsFileName = "clients.txt";

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

    newClient.accountNumber   = io_utils::readString("\nEnter account number: ");
    newClient.pinCode         = io_utils::readString("\nEnter pin code: ");
    newClient.name            = io_utils::readString("\nEnter name: ");
    newClient.phone           = io_utils::readString("\nEnter phone number: ");
    newClient.accountBalance  = io_utils::readPositiveNumber("\nEnter account balance: ");

    return newClient;
}

// Add a single line of data to a file
void addDataLineToFile(const string& fileName, const string& stDataLine) {
    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open()) {
        myFile << stDataLine << endl;
        myFile.close();
    } else {
        cout << "\nError: Unable to open file " << fileName << endl;
    }
}

// Add a new client and save to file
void addNewClient() {
    stClient client = readNewClient();
    addDataLineToFile(clientsFileName, convertRecordToLine(client));
}

// Loop to add multiple clients
void addClients() {
    char addMore = 'Y';

    do {
        system("cls");
        cout << "\nAdding new clients:\n\n";

        addNewClient();

        cout << "\nClient added successfully, do you need to add more clients? ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (toupper(addMore) == 'Y');
}

int main() {
    addClients();

    // Wait for user input before closing
    system("pause>0");
}