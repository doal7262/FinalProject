#include <iostream>
#include "FinalProject.h"

using namespace std;

void displayMenu(); // prototype for menu display
void insertCommands(); // prototype for inserting commands

/* Here in the main file I want it only to show it doing one thing, and that is displaying the switch for
commands. This main also has two classes difined, ht is the HashTable an T is the TextAnswer class */
int main()
{
    cout << "J.A.R.V.I.S ONLINE" << endl;

    // Declarations
    int input;
    bool quit = false;
    string command;
    //int cmdNumber;


    // Class Declarations
    HashTable ht;
    TextAnswer T;
    Math m;

    //displayMenu();
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
        case 1: // Weather
            T.Info();
            break;

        case 2: // Info
            T.Greeting();
            break;

        case 3: // Greeting
            T.Weather();
            break;

        case 4: // Search
            //string command;
            cout << "input a command" << endl;
            cin >> command;
            ht.findItem(command);
            break;

        case 5: // cmdList
            ht.printInventory();
            break;

        case 6: // Math
            m.initMath();
            break;

        case 7: // Game
            T.Game();
            break;

        case 8: // Quit
            cout << "GoodBye" << endl;
            quit = true;
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
    cout << "Press 4 to search for a command or 5 for the full list" << endl;
    return;
}

/* This is here to add all existing commands into a hashtable so it can be searched for and listed */
void insertCommands()
{
    HashTable ht;

    ht.insertItem("Info", 1);
    ht.insertItem("Greeting", 2);
    ht.insertItem("Weather", 3);
    ht.insertItem("Search", 4);
    ht.insertItem("cmdList", 5);
    ht.insertItem("Math", 6);
    ht.insertItem("Game", 7);
    ht.insertItem("Quit", 8);
}
