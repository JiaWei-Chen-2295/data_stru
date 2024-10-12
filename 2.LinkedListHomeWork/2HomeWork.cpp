#include <iostream>
#include <SimpleListNode.hpp>

using namespace std;
/*
===2===
将两个非递减的有序链表合并为一个非递增的有序链表。
要求结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间。表中允许有重复的数据。
*/
ListNode* InsertAndReverseTwoList(ListNode *list1, ListNode *list2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *res = dummyHead;

    //ListNode *pre = nullptr;
    while(list1 != nullptr && list2 != nullptr)
    {
        if(list1 -> val < list2 -> val)
        {
            ListNode *tmp = list1 -> next;
            list1 -> next = res -> next;
            res -> next = list1;
            list1 = tmp;
        } else {
            ListNode *tmp = list2 -> next;
            list2 -> next = res -> next;
            res -> next = list2;
            list2 = tmp;
        }
    }

    while (list1 != nullptr)
    {
        ListNode* temp = list1 -> next;
        list1 -> next = res -> next;
        res -> next = list1;
        list1 = temp;
    }

    
    while (list2 != nullptr)
    {
        ListNode* temp = list2 -> next;
        list2 -> next = res -> next;
        res -> next = list2;
        list2 = temp;
    }

    delete dummyHead;
    return res -> next;
}
int main()
{
    ListNode *list1 = new ListNode();
    EndInsertEles(list1, {1, 4 ,5 ,6 ,7, 8});
    list1 = list1 -> next;
    cout << "list1 is" << endl;
    Print(list1);

    ListNode *list2 = new ListNode();
    EndInsertEles(list2, {2, 3 ,4 ,6 ,7, 9});
    list2 = list2 -> next;
    cout << "list2 is" << endl;
    Print(list2);

    cout << "the result is " << endl;
    Print(InsertAndReverseTwoList(list1, list2));

    return 0;
}