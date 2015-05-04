#ifndef FINALPROJECT_H
#define FINALPROJECT_H

/* This struct is here to help with the hashtable, this defines that a node in the hashtable will have
a name and a pointer so that it can link with more nodes */
struct Item
{
    std::string name = "";
    int cmdNumber = 0;
    Item *next = NULL;

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

/* This class is specifically for Math, its purpose is to do basic math. Once the user inputs math
initMath will be called and from there you can do addition, subtraction, multiplication, division
and take a ratio */
class Math
{
public:
    //Math();
    //~Math();
    int initMath();
    void setValues(int num1, int num2);
    int addition(int num1, int num2);
    int subtraction(int num1, int num2);
    int multiplication(int num1, int num2);
    int division(int num1, int num2);
    int Ratio(int num1, int num2);
protected:
private:

};

/* This class is here specifically for the simple functions that pretty much only consist of couts.
this helps with housekeeping. */
class TextAnswer
{
    public:
        void Game();
        void Info();
        void Greeting();
        void Weather();
    protected:
    private:

};

#endif // FINALPROJECT_H
