#include <iostream>
#include <cstring>

#include "Hashtable.h"

using namespace std;

int main()
{
    Hashtable h;

    h.add_item("maiw","sfdsf");
    h.add_item("maiw","sfdsf");
    h.add_item("maiw","sfdsf");
    h.add_item("wiam","fsdsf");

    h.print_hash_table();

    h.print_items_inIndex(0);

    cout<<endl;

    h.find_string("wiam");

}

