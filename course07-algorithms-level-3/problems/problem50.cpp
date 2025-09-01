#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../helpers/helperFunctions.h"
using namespace std;

/*
==================================================
   Problem : Delete a client by account number 
             from file storage
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
    vector<string> vString = helperFunctions::splitString(str, separator);

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

// Mark a client for deletion
bool markClientForDeleteByAccountNumber(const string& accountNumber, vector<stClient>& vClients) {
    for (stClient& c : vClients) {
        if (c.accountNumber == accountNumber) {
            c.markForDelete = true;
            return true;
        }
    }
    return false;
}

// Save all clients back to file
vector<stClient> saveClientsDataToFile(const string& fileName, const vector<stClient>& vClients) {
    fstream myFile(fileName, ios::out);

    if (myFile.is_open()) {
        for (const stClient& c : vClients) {
            if (!c.markForDelete) {
                myFile << convertRecordToLine(c) << endl;
            }
        }
        myFile.close();
    }

    return vClients;
}

// Delete a client by account number
bool deleteClientByAccountNumber(const string& accountNumber, vector<stClient>& vClients) {
    stClient client;
    char answer = 'n';

    if (findClientByAccountNumber(accountNumber, vClients, client)) {
        printClientRecord(client);

        cout << "\n\nAre you sure you want to delete this client? (y/n): ";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            markClientForDeleteByAccountNumber(accountNumber, vClients);
            saveClientsDataToFile(clientsFileName, vClients);

            vClients = loadClientsDataFromFile(clientsFileName);
            cout << "\n\nClient deleted successfully.\n";
            return true;
        }
    } else {
        cout << "\nClient with account number (" << accountNumber << ") is NOT found!";
    }

    return false;
}


int main() {
    // Read account number from user
    vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

    string accountNumber = helperFunctions::readString("Please enter account number ? ");
    deleteClientByAccountNumber(accountNumber, vClients);

    // Wait for user input before closing
    system("pause>0");
}