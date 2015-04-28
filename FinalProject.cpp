#include <iostream>
#include "FinalProject.h"

using namespace std;

void displayMenu(); // prototype for menu display
void insertCommands(); // prototype for inserting commands

/* Here in the main file I want it only to show it doing one thing, and that is displaying the switch for
commands. This main also has two classes difined, ht is the HashTable an T is the TextAnswer class */
int main()
{
    // Declarations
    int input;
    bool quit = false;
    string command;

    HashTable ht;
    TextAnswer T;

    insertCommands(); // This inserts all available commands in a HashTable

/* I like to use switches for my inputs, its makes it look a lot cleaner and makes any wrong input
have a response.*/
    while(quit != true)
    {
        displayMenu();
        cin >> input;

        // Clear out cin
        cin.clear();
        cin.ignore(10000, '\n');

        switch (input)
        {
        case 'Weather':
            break;

        case 'Info':
            T.Info();
            break;

        case 'Greeting':
            T.Greeting();
            break;

        case 'Search':
            //string command;
            cout << "input a command" << endl;
            cin >> command;
            ht.findItem(command);
            break;

        case 'cmdList':
            ht.printInventory();
            break;

        default:
            cout << "Invalid Input" << endl;
            cout << endl;
            cout << "If you are unsure of what options you have, you can input cmdList for all available command or Search to look for a particular command" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}


/*This will appear everytime the menu starts */
void displayMenu()
{
    cout << "J.A.R.V.I.S ONLINE" << endl;
    return;
}

/* This is here to add all existing commands into a hashtable so it can be searched for and listed */
void insertCommands()
{
    HashTable ht;

    ht.insertItem("weather");
    ht.insertItem("Info");
    ht.insertItem("Greeting");
    ht.insertItem("Search");
    ht.insertItem("cmdList");
}
