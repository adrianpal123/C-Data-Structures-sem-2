#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
using namespace std;
class Hashtable
{

private:
    static const int TableSize=10;
    struct item
    {
        string name;
        string drink;
        item* next;
    };

    item* HashTable[TableSize];
public:
    Hashtable();
    Hashtable(string x, string y);
    virtual ~Hashtable();
    int Hash(string key);
    friend ostream& operator << (ostream &, Hashtable);
    void add_item(string name, string drink);
    int number_of_items_inIndex(int index);
    void print_hash_table();
    void print_items_inIndex(int index);
    void find_string(string name);

protected:


};

#endif // HASHTABLE_H
