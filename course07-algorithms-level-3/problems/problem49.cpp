#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../helpers/io_utils.h"
#include "../../helpers/string_utils.h"
using namespace std;

/*
==================================================
   Problem: Find and display a client record by
            account number from a file.
   From   : Programming Advices – Course 7
   Date   : 2025-08-31
==================================================
*/

const string clientsFileName = "clients.txt";

// Client structure
struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

// Convert a line from file to a client struct
stClient convertLineToRecord(string str, string separator = "#//#")
{
    stClient newClient;
    vector<string> vString = string_utils::splitString(str, separator);

    newClient.accountNumber = vString[0];
    newClient.pinCode = vString[1];
    newClient.name = vString[2];
    newClient.phone = vString[3];
    newClient.accountBalance = stod(vString[4]);

    return newClient;
}

// Load all clients from file
vector<stClient> loadClientsDataFromFile(string fileName)
{
    vector<stClient> vClients;
    fstream myFile;
    myFile.open(fileName, ios::in);

    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            vClients.push_back(convertLineToRecord(line));
        }
        myFile.close();
    }

    return vClients;
}

// Print a single client record
void printClientRecord(stClient client)
{
    cout << "\nThe following are the account details:\n";
    cout << "\nAccount Number : " << client.accountNumber;
    cout << "\nPin Code       : " << client.pinCode;
    cout << "\nName           : " << client.name;
    cout << "\nPhone          : " << client.phone;
    cout << "\nAccount Balance: " << client.accountBalance;
}

// Find a client by account number
bool findClientByAccountNumber(string accountNumber, stClient &client)
{
    vector<stClient> vClients = loadClientsDataFromFile(clientsFileName);

    for (stClient &c : vClients)
    {
        if (c.accountNumber == accountNumber)
        {
            client = c;
            return true;
        }
    }

    return false;
}

int main()
{
    // Read account number from user
    string accountNumber = io_utils::readString("Please enter account number ?");

    stClient client;
    if (findClientByAccountNumber(accountNumber, client))
    {
        printClientRecord(client);
    }
    else
    {
        cout << "\nClient with account number (" << accountNumber << ") is NOT found!\n";
    }

    // Wait for user input before closing
    system("pause>0");
}