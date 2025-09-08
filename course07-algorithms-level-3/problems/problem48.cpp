#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../helpers/io_utils.h"
#include "../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Load bank clients data from file
            and display them in a formatted table.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
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
};

// Convert a client struct to a single line string
string convertRecordToLine(stClient client, string separator = "#//#") {
    string stClientRecord = "";

    stClientRecord += client.accountNumber + separator;
    stClientRecord += client.pinCode + separator;
    stClientRecord += client.name + separator;
    stClientRecord += client.phone + separator;
    stClientRecord += to_string(client.accountBalance);

    return stClientRecord;
}

// Read client data from user
stClient readNewClient() {
    stClient newClient;

    newClient.accountNumber  = io_utils::readString("\nEnter account number: ");
    newClient.pinCode        = io_utils::readString("\nEnter pin code: ");
    newClient.name           = io_utils::readString("\nEnter name: ");
    newClient.phone          = io_utils::readString("\nEnter phone number: ");
    newClient.accountBalance = io_utils::readPositiveNumber("\nEnter account balance: ");

    return newClient;
}

// Convert a line from file to a client struct
stClient convertLineToRecord(string str, string separator = "#//#") {
    stClient newClient;
    vector<string> vString = string_utils::splitString(str, separator);

    newClient.accountNumber  = vString[0];
    newClient.pinCode        = vString[1];
    newClient.name           = vString[2];
    newClient.phone          = vString[3];
    newClient.accountBalance = stod(vString[4]);

    return newClient;
}

// Load clients data from file into a vector
vector<stClient> loadClientsDataFromFile(string fileName) {
    vector<stClient> vClients;
    fstream myFile;
    myFile.open(fileName, ios::in);

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
void printClientRecord(stClient client) {
    cout << "| " << setw(16) << left  << client.accountNumber;
    cout << "| " << setw(10) << left  << client.pinCode;
    cout << "| " << setw(20) << left  << client.name;
    cout << "| " << setw(15) << left  << client.phone;
    cout << "| " << setw(10) << right << fixed << client.accountBalance;
    cout << endl;
}

// Print all clients in a formatted table
void printAllClientsData(vector<stClient>& vClients) {
    cout << "\n\t\t\t\t\t\tClient list (" << vClients.size() << ") client(s).\n";

    cout << "\n| " << setw(16) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(20) << left << "Client Name";
    cout << "| " << setw(15) << left << "Phone";
    cout << "| " << setw(10) << right << "Balance";
    cout << "\n" << string(100, '_') << "\n\n";

    for (stClient& client : vClients) {
        printClientRecord(client);
        cout << endl;
    }
}

// Main function
int main() {
    // Load clients from file
    vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

    // Display all clients
    printAllClientsData(vClients);

    // Wait for user input before closing
    system("pause>0");
}