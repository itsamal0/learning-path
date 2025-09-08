#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../helpers/io_utils.h"
#include "../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem : Update a client by account number
             in file storage
   From    : Programming Advices – Course 7
   Date    : 2025-09-01
==================================================
*/

const string clientsFileName = "clients.txt";

// Client structure
struct stClient {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
};

// Convert a line from file to a client struct
stClient convertLineToRecord(const string& str, const string& separator = "#//#") {
    stClient newClient;
    vector<string> vString = string_utils::splitString(str, separator);

    newClient.accountNumber  = vString[0];
    newClient.pinCode        = vString[1];
    newClient.name           = vString[2];
    newClient.phone          = vString[3];
    newClient.accountBalance = stod(vString[4]);

    return newClient;
}

// Load all clients from file
vector<stClient> loadClientsDataFromFile(const string& fileName) {
    vector<stClient> vClients;
    fstream myFile(fileName, ios::in);

    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            vClients.push_back(convertLineToRecord(line));
        }
        myFile.close();
    }

    return vClients;
}

// Print a single client record
void printClientRecord(const stClient& client) {
    cout << "\nThe following are the account details:\n";
    cout << "\nAccount Number : " << client.accountNumber;
    cout << "\nPin Code       : " << client.pinCode;
    cout << "\nName           : " << client.name;
    cout << "\nPhone          : " << client.phone;
    cout << "\nAccount Balance: " << client.accountBalance;
}

// Find a client by account number
bool findClientByAccountNumber(const string& accountNumber, const vector<stClient>& vClients, stClient& client) {
    for (const stClient& c : vClients) {
        if (c.accountNumber == accountNumber) {
            client = c;
            return true;
        }
    }
    return false;
}

// Convert a client struct to a line for saving
string convertRecordToLine(const stClient& client, const string& separator = "#//#") {
    string record = "";

    record += client.accountNumber + separator;
    record += client.pinCode + separator;
    record += client.name + separator;
    record += client.phone + separator;
    record += to_string(client.accountBalance);

    return record;
}

// Save all clients back to file
vector<stClient> saveClientsDataToFile(const string& fileName, const vector<stClient>& vClients) {
    fstream myFile(fileName, ios::out);

    if (myFile.is_open()) {
        for (const stClient& c : vClients) {
            myFile << convertRecordToLine(c) << endl;
        }
        myFile.close();
    }

    return vClients;
}

// Update a client by account number
bool updateClientByAccountNumber(const string& accountNumber, vector<stClient>& vClients) {
    stClient client;
    char answer = 'n';

    if (findClientByAccountNumber(accountNumber, vClients, client)) {
        printClientRecord(client);

        cout << "\n\nAre you sure you want to update this client? (y/n): ";
        cin >> answer;

        if (toupper(answer) == 'Y') {
	    // Clear input buffer
            cin.ignore(1000, '\n');

            stClient updatedClient;
            updatedClient.accountNumber = accountNumber;
            updatedClient.pinCode = io_utils::readString("\nEnter new pin code: ");
            updatedClient.name = io_utils::readString("\nEnter new name: ");
            updatedClient.phone = io_utils::readString("\nEnter new phone: ");
            updatedClient.accountBalance = io_utils::readPositiveNumber("\nEnter new account balance: ");

            // Update the client in the vector
            for (stClient& c : vClients) {
                if (c.accountNumber == accountNumber) {
                    c = updatedClient;
                    break;
                }
            }

            // Save updated clients to file
            saveClientsDataToFile(clientsFileName, vClients);
            cout << "\n\nClient updated successfully.\n";
            return true;
        }
    } else {
        cout << "\nClient with account number (" << accountNumber << ") is NOT found!";
    }

    return false;
}


int main() {
    // Load clients from file
    vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

    // Read account number from user
    string accountNumber = io_utils::readString("Please enter account number ? ");
    updateClientByAccountNumber(accountNumber, vClients);

    // Wait for user input before closing
    system("pause>0");
}