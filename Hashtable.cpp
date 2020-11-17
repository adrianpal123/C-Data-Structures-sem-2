#include "Hashtable.h"
#include <iostream>
#include <cstring>

using namespace std;

Hashtable::Hashtable()
{
    for (int i=0; i<TableSize; i++)
    {
        HashTable[i]=new item;
        HashTable[i]->name="empty";
        HashTable[i]->drink="empty";
        HashTable[i]->next=NULL;

    }
}

Hashtable::Hashtable(string x, string y)
{
    for (int i=0; i<TableSize; i++)
    {
        HashTable[i]=new item;
        HashTable[i]->name=x;
        HashTable[i]->drink=y;
        HashTable[i]->next=NULL;

    }
}

Hashtable::~Hashtable()
{
    //dtor
}

int Hashtable :: Hash(string key)
{
    int index;

    int sum=0;

    for (int i=0; i<key.length( ); i++)
    {
        sum=sum+(int)key[i];
    }


    index=sum%TableSize;

    return index;

}

/*ostream& operator << (ostream &st, Hashtable HashTable)
{
    for (int i=0; i<TableSize; i++)
    {
        st<<HashTable[i]=new item<<" ";
        st<<HashTable[i]->name="empty"<<" ";
        st<<HashTable[i]->drink="empty"<<" ";
        st<<HashTable[i]->next=NULL;

    }

    return st;
}*/

void Hashtable:: add_item(string name, string drink)
{
    Hashtable h;
    int index=Hash(name);
    if (HashTable[index]->name=="empty")
    {
        HashTable[index]->name=name;
        HashTable[index]->drink=drink;
    }
    else
    {
        item* Ptr= HashTable[index];
        item* n=new item;
        n->name=name;
        n->drink=drink;
        n->next=NULL;

        while (Ptr->next!=NULL)
            Ptr=Ptr->next;

        Ptr->next=n;

    }

}

int Hashtable:: number_of_items_inIndex(int index)
{
    int count=0;
    if (HashTable[index]->name=="empty")
    {
        return count;
    }
    else
    {
        count++;
        item *Ptr= HashTable[index];
        while (Ptr->next!=NULL)
        {
            Ptr=Ptr->next;
            count++;
        }

        return count;


    }
}

void Hashtable:: print_hash_table()
{
    int number;
    for (int i=0;i<TableSize;i++)
    {
        number=number_of_items_inIndex(i);
        cout<<"--------------"<<endl;;
        cout<<"index= "<< i<< endl;
        cout<<HashTable[i]->name<<endl;
        cout<<HashTable[i]->drink<<endl;
        cout<<"number of items="<<number<<endl;
        cout<<"--------------"<<endl;

    }
}

void Hashtable::print_items_inIndex(int index)
{
    item* Ptr=HashTable[index];
    if (Ptr!=NULL)
    {
        while (Ptr->next!=NULL)
        {
            cout<<Ptr->name<<" ";
            Ptr=Ptr->next;
        }
    cout<<Ptr->name;

    }
    else
    {
        cout<<"nu exista nimic in acest bucket";
    }
}

void Hashtable:: find_string(string nume)
{
    int index=Hash(nume);
    item* Ptr=HashTable[index];
    bool found=false;

    string drink;


    while (Ptr!=NULL)
    {
        if (Ptr->name==nume)
        {
            found=true;
            drink=Ptr->drink;
        }
        Ptr=Ptr->next;
    }

    if (found==true)
    {
        cout<<"numele drk: "<<drink;
    }
    else
        cout<<"nu am gasit drk";

}

