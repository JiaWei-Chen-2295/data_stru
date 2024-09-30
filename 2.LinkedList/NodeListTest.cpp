#include "NodeList.hpp"
#include "Status.h"
#include <iostream>
#include <new>

using namespace std;

int main()
{
    // init 
    NodeList *L;
    // OK = 0 | 0 = false
    if(InitList(L) != ERROR) cout << "init success" << endl;
    cout << "List address is: " << L << endl;
    cout << "List size is: " << L -> size << endl;

    // add end Node
    cout << "===Add end Node===" << endl;
    for(int i = 0; i < 10; i++)
    {
        EndListInsert(L, i);
    }
    cout << "List size is: " << L -> size << endl;
    PrintListVal(*L);
    cout << "================" << endl;

    // add index Node
    cout << "===Add index Node===" << endl;
    cout << "middle insert 5 to 100" << endl;
    ListInsert(L, 5, 100);
    PrintListVal(*L);

    cout << "middle insert 1 to 111" << endl;
    ListInsert(L, 0, 111);
    PrintListVal(*L);

    cout << "middle insert size to 555" << endl;
    ListInsert(L, L -> size, 555);
    PrintListVal(*L);
    cout << "================" << endl;
    
    cout << "===Find Node===" << endl;
    
    cout << "find head" << endl;
    cout << FindNodeIndex(L,111) << endl;

    cout << "find middle" << endl;
    cout << FindNodeIndex(L,100) << endl;
    
    cout << "find end" << endl;
    cout << FindNodeIndex(L,555) << endl; // 

    cout << "===============" << endl;
    
    cout << "===Delete Node===" << endl;
    
    cout << "delete index 5" << endl;
    DeleteNode(L, 5);
    PrintListVal(*L);

    cout << "delete index 1" << endl;
    DeleteNode(L, 1);
    PrintListVal(*L);

    cout << "delete index end" << endl;
    DeleteNode(L, L -> size);
    PrintListVal(*L);
    
    cout << "===============" << endl;
    system("pause");
    return 0;
}