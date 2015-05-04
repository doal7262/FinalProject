#include <iostream>
#include "FinalProject.h"
#include <string>

using namespace std;
/* Constructor for the hashtable, defines a name for each point in the array and sets their pointers
to NULL */
HashTable::HashTable()
{
    hashTable = new Item*[10];
    for(int i = 0; i < tableSize; i++)
    {
        hashTable[i] = new Item();
        hashTable[i]->name = "";
        hashTable[i]->next = NULL;
    }
}

/* Destructor for the hashtable, goes through the array and deletes everything to
fight memory leaks */
HashTable::~HashTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        delete hashTable[i];
    }
}

/* This exists to take a string and find its hash value, after its found it will be sorted to find
its index, this is a helper function for other functions like insertItem and findItem */
int HashTable::initHash(std::string name)
{
    int hashT = 0;
    int index = 0;

    for(unsigned int i = 0; i < name.length(); i++)
    {
        hashT = hashT + (int)name[i];
    }

    index = hashT % tableSize;

    return index;
}

/* This function will take the string name and add it to the hashtable, if there is not enough space
in the array for it the function will set the array node's pointer so that it forms a linked list */
void HashTable::insertItem(std::string name, int cmdNumber)
{
    int index = initHash(name);

    if(hashTable[index]->name == "")
    {
        hashTable[index]->name = name;
        hashTable[index]->cmdNumber = cmdNumber;
        //std::cout << hashTable[index]->cmdNumber << ". " << hashTable[index]->name << std::endl;
    }

    else
    {
        Item * Ptr = hashTable[index];
        Item * newItem = new Item(name);
        //n->name = name;
        std::cout << newItem->name << std::endl;
        while(Ptr != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr = newItem; /// Ptr->next = newItem - you already iterated until Ptr is NULL so you cant point NULL at something :)
    }
    //std::cout << "Item Added" << std::endl;

}

/* This function will print everything that is in the hashtable */
void HashTable::printInventory()
{
    for(int i = 0; i < tableSize; i++)
    {
        Item * Ptr = hashTable[i];
        if(hashTable[i]->name != "")
            std::cout << "command: " << hashTable[i]->name << std::endl;
        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
            if(Ptr->name != "")
                std::cout << "command: " << hashTable[i]->name << std::endl;
        }
    }
}

/* This function will look to see if it can match a name with the input given, if it does
it will return it found the item. */
Item* HashTable::findItem(std::string name)
{
    int sum = 0;
    char ch;
    //bool found = true;
    for(unsigned int i = 0; i < name.length(); i++)
    {
        ch = (char)name[i];
        sum = sum + int(ch);
    }
    sum = sum % tableSize;
    Item *temp = new Item();
    temp = hashTable[sum];
    while(temp != NULL)
    {
        if(temp->name == name)
        {
            std::cout << "found" << std::endl;
            return temp; ///if found return pointer to location in hash of temp
        }
        temp = temp->next;

    }
    std::cout << "not found" << std::endl;
    return NULL; ///if not found return NULL
}

int Math::initMath()
{
    int mathCommand;
    int num1;
    int num2;
    int answer;

    std::cout << "=====Math=====" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Ratio" << std::endl;

    switch(mathCommand)
    {
    case 1:
        std::cout << "Input two numbers you want to add" << std::cout;
        std::cin >> num1 >> num2;
        answer = addition(num1,num2);
        return answer;

    case 2:
        std::cout << "Input two numbers you want to subtract" << std::cout;
        std::cin >> num1 >> num2;
        answer = subtraction(num1,num2);
        return answer;

    case 3:
        std::cout << "Input two numbers you want to multiply" << std::cout;
        std::cin >> num1 >> num2;
        answer = multiplication(num1,num2);
        return answer;

    case 4:
        std::cout << "Input two numbers you want to divide" << std::cout;
        std::cin >> num1 >> num2;
        answer = division(num1,num2);
        return answer;

    case 5:
        std::cout << "Input two numbers you want to take a ratio of" << std::cout;
        std::cin >> num1 >> num2;
        answer = Ratio(num1,num2);
        return answer;
    }
}

/*
int Math::Math()
{

}

int Math::~Math()
{

}
*/

int Math::addition(int num1, int num2)
{
    int finalVal = num1 + num2;
    return finalVal;
}

int Math::subtraction(int num1, int num2)
{
    int finalVal = num1 - num2;
    return finalVal;
}

int Math::multiplication(int num1, int num2)
{
    int finalVal = num1 * num2;
    return finalVal;
}

int Math::division(int num1, int num2)
{
    int finalVal = num1 / num2;
    return finalVal;
}

int Math::Ratio(int num1, int num2)
{
    int finalVal = num1 % num2;
    return finalVal;
}

void TextAnswer::Game()
{
    std::string gameCommand;
    //bool acceptable_answer = true;
    std::cout << "Do you want to fight the (d)ragon or (s)torm the castle?" << std::endl;
    std::cin >> gameCommand;

    if (gameCommand == "d")
    {
        std::string gameCommand2;
        std::cout << "Will you fight the dragon with a (b)ow, (s)word, or (m)ace" << std::endl;
        std::cin >> gameCommand2;

        if (gameCommand2 == "b")
        {
            std::cout << "Dragon incenerated you, game over." << std::endl;
        }

        else if(gameCommand2 == "s")
        {
            std::cout << "You successfully killed the dragon, you win!" << std::endl;
        }

        else if(gameCommand2 == "m")
        {
            std::cout << "Dragon killed you, game over" << std::endl;
        }

        else if (gameCommand == "a")
        {
            std::cout << "You have no army to storm the castle with, you died" << std::endl;
        }

        else
        {
            std::cout << "You entered a wrong command, you lose!"<< std::endl;
        }
    }

    else
    {
        std::cout << "That command was not valid" << std::endl;
    }
}

/* Simple response to input 'Weather' */
void TextAnswer::Weather()
{
    std::cout << "How about look outside?" << std::endl;
}

/* Simple response to input 'Info' */
void TextAnswer::Info()
{
    std::cout << "This is J.A.R.V.I.S, a program designed to do very specific tasks, at moment there is only a certain amount of tasks it can do, to find all of these please input cmdList for a list of all operations" << std::endl;
}

/* Simple response to input 'Greeting' */
void TextAnswer::Greeting()
{
    std::cout << "Hello, I am J.A.R.V.I.S, input cmdList for a full list of my commands." << std::endl;
}
