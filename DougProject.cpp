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
    //int cmdNumber;

    HashTable ht;
    TextAnswer T;

    displayMenu();
    insertCommands(); // This inserts all available commands in a HashTable

/* I like to use switches for my inputs, its makes it look a lot cleaner and makes any wrong input
have a response.*/
    while(quit != true)
    {
        cin >> input;
        // Clear out cin
        cin.clear();
        cin.ignore(10000, '\n');
        string c;
        insertCommands();

        switch (input)
        {
        case 1: // Weather
            T.Weather();
            break;

        case 2: // Info
            T.Info();
            break;

        case 3: // Greeting
            T.Greeting();
            break;

        case 4: // Search
            cout << "input a command" << endl;
            getline(cin, c);
            ht.findItem(c);
            break;

        case 5: // cmdList
            ht.printInventory();
            break;

        case 6: // Quit
            cout << "GoodBye" << endl;
            quit = true;
            break;

        case 7:
            cout<<"Here is the list of commands that you can input:"<<endl;
            displayMenu();


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
    cout<<"--------------------"<<endl;
    cout << "1. Weather"<<endl;
    cout << "2. Info"<<endl;
    cout<< "3. Greeting"<<endl;
    cout<<"4. Search"<<endl;
    cout<<"5. Print the Inventory"<<endl;
    cout<<"6. Quit"<<endl;
    cout<<"7. CommandList"<<endl;
    return;
}

/* This is here to add all existing commands into a hashtable so it can be searched for and listed */
void insertCommands()
{
    HashTable ht;

    ht.insertItem("Weather", 1);
    ht.insertItem("Info", 2);
    ht.insertItem("Greeting", 3);
    ht.insertItem("Search", 4);
    ht.insertItem("cmdList", 5);
}
