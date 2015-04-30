#ifndef FINALPROJECT_H
#define FINALPROJECT_H

/* This struct is here to help with the hashtable, this defines that a node in the hashtable will have
a name and a pointer so that it can link with more nodes */
struct Item
{
    std::string name;
    int cmdNumber;
    Item *next;

    Item(){};

    Item(std::string name)
    {
        name = name;
    }
};

/* This class is specifically for HashTables, its purpose is to have functions that will serve
J.A.R.V.I.S well when he needs to find a certain command or list all of them */
class HashTable
{
    public:
        HashTable();
        ~HashTable();
        int initHash(std::string name);
        void insertItem(std::string name, int cmdNumber);
        void printInventory();
        Item * findItem(std::string name);
    protected:
    private:
        Item **hashTable;
        int tableSize = 10;
};

/* This class is here specifically for the simple functions that pretty much only consist of couts.
this helps with housekeeping. */
class TextAnswer
{
    public:
        void Info();
        void Greeting();
        void Weather();
    protected:
    private:

};

#endif // FINALPROJECT_H
