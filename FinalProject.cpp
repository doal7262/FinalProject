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
    int num1;
    int num2;


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
        case 1: // Info
            T.Info();
            break;

        case 2: // Greeting
            T.Greeting();
            break;

        case 3: // Weather
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

        case 6: // Addition
            //quit = true;
            cout << "Enter two numbers for addition" << endl;
            cin >> num1 >> num2;
            m.addition(num1, num2);
            break;

        case 7: // Subtraction
            cout << "Enter two numbers for subtraction" << endl;
            cin >> num1 >> num2;
            m.subtraction(num1, num2);
            break;

        case 8: // Multiplication
            cout << "Enter two numbers for multiplication" << endl;
            cin >> num1 >> num2;
            m.multiplication(num1, num2);
            break;

        case 9: // Division
            cout << "Enter two numbers for Division" << endl;
            cin >> num1 >> num2;
            m.division(num1, num2);
            break;

        case 10: // Ratio
            cout << "Enter two numbers to take a ratio of" << endl;
            cin >> num1 >> num2;
            m.Ratio(num1, num2);
            break;


        case 11: // Game
            T.Game();
            break;

        case 12: // Quit
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

    cout << "=====Main Menu=====" << endl;
    cout << "1. Info" << endl;
    cout << "2. Greeting" << endl;
    cout << "3. Weather" << endl;
    cout << "4. Search" << endl;
    cout << "5. Command List" << endl;
    cout << "6. Addition" << endl;
    cout << "7. Subtraction" << endl;
    cout << "8. Muliplication" << endl;
    cout << "9. Division" << endl;
    cout << "10. Ratio" << endl;
    cout << "11. Play a Game" << endl;
    cout << "12. Quit" << endl;

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
    ht.insertItem("Addition", 6);
    ht.insertItem("Subtraction", 7);
    ht.insertItem("Multiplication", 8);
    ht.insertItem("Division", 9);
    ht.insertItem("Ratio", 10);
    ht.insertItem("Game", 11);
    ht.insertItem("Quit", 12);
}
