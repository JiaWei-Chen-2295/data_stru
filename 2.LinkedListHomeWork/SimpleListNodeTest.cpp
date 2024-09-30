#include <iostream>
#include <SimpleListNode.hpp>

int main()
{
    ListNode *L = new ListNode(-1);
    ListNode *L_head = L;

    EndInsertEles(L, {2, 4, 5, 34, 5, 6});
    Print(L_head);
    Print(L);

    return 0;
}