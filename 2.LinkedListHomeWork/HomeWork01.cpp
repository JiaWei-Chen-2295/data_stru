#include <iostream>

#include <SimpleListNode.hpp>

using namespace std;

/**
 * leetcode 回文链表判断
 */

ListNode* reverse_list(ListNode *head)
{
    ListNode *now = head, *per = nullptr;
    while (now != nullptr)
    {
        ListNode *tmp = now -> next;
        now -> next = per;
        per = now;
        now = tmp;
    }
    return per;
}
ListNode* getHelfOfList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast -> next != nullptr && fast -> next -> next != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    } 
    return slow;
}
bool isHuiWen(ListNode *head)
{
    ListNode *first = head;
    ListNode *second = getHelfOfList(head);

    second  = reverse_list(second);

    while (first != nullptr && second != nullptr)
    {
        if(first -> val != second -> val)
            return false;
        first = first -> next;
        second = second -> next;
    }

    return true;
}

int main()
{
    ListNode *l = new ListNode();
    
    EndInsertEles(l, {2, 4, 5, 4, 2}); 
    
    ListNode *l_head = l -> next;

    Print(l_head);

    cout << isHuiWen(l_head);

    return 0;
}