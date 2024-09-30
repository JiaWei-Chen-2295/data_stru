#include <iostream>
#include <initializer_list>

using namespace std;

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

typedef struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v): val(v),next(nullptr) {}
    ListNode(int v, ListNode *n): val(v),next(n) {}
} ListNode;

void Print(ListNode *LN)
{
    cout << "[" ;
    while(LN != nullptr)
    {
        cout << LN -> val << " ";
        LN = LN -> next;
    }
    cout << "]" << endl;
}

void EndInsertEles(ListNode *L, initializer_list<int> nums)
{
    for (auto num : nums)
    {
        L -> next = new ListNode(num);
        L = L -> next;
    }
}

#endif
