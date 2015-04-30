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
        hashTable[i] = new Item;
        hashTable[i]->name = "nothing";
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

    for(int i = 0; i < name.length(); i++)
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

    if(hashTable[index]->name == "nothing")
    {
        hashTable[index]->name = name;
        hashTable[index]->cmdNumber = cmdNumber;
        std::cout << hashTable[index]->cmdNumber << ". " << hashTable[index]->name << std::endl;
    }

    else
    {
        Item * Ptr = hashTable[index];
        Item * n = new Item;
        n->name = name;
        std::cout << n->name << std::endl;
        n->next = NULL;
        while(Ptr != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
    //std::cout << "Item Added" << std::endl;

}

/* This function will print everything that is in the hashtable */
void HashTable::printInventory()
{
    for(int i = 0; i < tableSize; i++)
    {
        Item * Ptr = hashTable[i];
        if(hashTable[i]->name != "nothing")   
            std::cout << "command: " << hashTable[i]->name << std::endl;
        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
            if(Ptr->name != "nothing")      
                std::cout << "command: " << std::endl;
        }
    }
}

/* This function will look to see if it can match a name with the input given, if it does
it will return it found the item. */
Item* HashTable::findItem(std::string name)
{
    int sum = 0;
    char ch;
    bool found = true;
    for(int i = 0; i < name.length(); i++)
    {
        ch = (char)name[i];
        sum = sum + int(ch);
    }
    sum = sum % tableSize;
    Item *temp = new Item;
    temp = hashTable[sum];
    while(temp->name != name)
    {
        if(temp-> next != NULL)
        {
            temp = temp->next;
        }
        else
        {
            std::cout << "Not found" << std::endl;
            found = false;
            break;
        }
    }
    if(found == true)
        std::cout << "found" << std::endl;
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