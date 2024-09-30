/**
2.算法设计题
（3）已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法，用于求出A与B的交集，并将结果存放在A链表中。
（4）已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B的差集（仅由在A中出现而不在B中出现的元素所构成的集合），并将结果以同样的形式存储，同时返回该集合的元素个数。

（8）设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素（mink和maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同）。
（9）已知p指向双向循环链表中的一个节点，其节点结构为data、prior、next这3个域，设计算法change(p)，交换p所指向的节点及其前驱节点的顺序。
*/
#include <iostream>
#include <SimpleListNode.hpp>
#include <SqList.hpp>
#include <Status.h>

using namespace std;

// ==1==
// 将两个递增的有序链表合并为一个递增的有序链表。
//要求结果链表仍使用原来两个链表的存储空间，
//不另外占用其他的存储空间。表中不允许有重复的数据。
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2);
ListNode* mergeTwoLists2(ListNode *l1, ListNode *l2);
/*
===2===
将两个非递减的有序链表合并为一个非递增的有序链表。
要求结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间。表中允许有重复的数据。
*/
ListNode* reverseList(ListNode *L);
ListNode* mergeAndChangeLists(ListNode *l1, ListNode *l2);
/**
 * （5）设计算法将一个带头节点的单链表A分解为两个具有相同结构的链表B和C，
 * 其中B表的节点为A表中值小于0的节点，而C表的节点为A表中值大于0的节点
 * （链表A中的元素为非零整数，要求B、C表利用A表的节点）。
 */
void splitList(ListNode *oldNode, ListNode *&B, ListNode *&C);
// （6）设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的节点。
int MaxNodeVal(ListNode *L);
/**
 * ===7===
 * 设计一个算法，将链表中所有节点的链接方向“原地”逆转，
 * 即要求仅利用原表的存储空间，换句话说，要求算法的空间复杂度为O(1)。
 */
ListNode* reverseList2(ListNode *L);
/**
 * (10）已知长度为n的线性表A采用顺序存储结构，请设计一个时间复杂度为O（n)、空间复杂度为O（1）的算法，
 * 该算法可删除线性表中所有值为item的数据元素。
 * 
 * 时间复杂度尚有问题
 */
void DeleteItemByItem(SqList *list, int ele);


int main()
{
   cout << "==============1================" << endl;
   ListNode *L1 = new ListNode(2);
   ListNode *L1_head = L1;

   for(int i = 4; i < 10; i+=2)
   {
       L1->next = new ListNode(i);
       L1 = L1->next;
   }
   EndInsertEles(L1, {10});

   ListNode *L2 = new ListNode(1);
   ListNode *L2_head = L2;
   for(int i = 3; i < 10; i+=2)
   {
       L2->next = new ListNode(i);
       L2 = L2->next;
   }
   EndInsertEles(L2, {10});

   
   cout << "first:" << endl;
   Print(L1_head);
   cout << "second:" << endl;
   Print(L2_head);

   cout << "merge:" << endl;
   Print(mergeTwoLists2(L1_head, L2_head));
   cout << "==============================" << endl << endl;


   cout << "==============2================" << endl;
   ListNode *L4 = new ListNode(1);
   ListNode *L4_head = L4;

   EndInsertEles(L4, {3, 3, 5, 5, 7});

   cout << "first:";
   Print(L4_head);

   ListNode *L5 = new ListNode(1);
   ListNode *L5_head = L5;

   EndInsertEles(L5, {2, 4, 4, 8, 8});

   cout << "second:";
   Print(L5_head);

   cout << "merged:" ;
   Print(mergeAndChangeLists(L4_head, L5_head));
   cout << "==============================" << endl << endl;


   cout << "==============5================" << endl;
   L4 = new ListNode(1);
   L4_head = L4;

   EndInsertEles(L4, {-3, 3, -8, 5, -7});
   
   cout << "start:";Print(L4_head);
   ListNode *L6 = new ListNode(-1); 
   ListNode *L7 = new ListNode(-1); 
   ListNode *L6_head = L6 -> next;ListNode *L7_head = L7 -> next;
   splitList(L4, L6, L7);
   cout << "B:" ;Print(L6_head);
   cout << "C:" ;Print(L7_head);
   cout << "==============================" << endl << endl;


   cout << "==============6================" << endl;
   L4 = new ListNode(1);
   L4_head = L4;

   EndInsertEles(L4, {3, 3, 5, 5, 7});

   cout << "start:";
   Print(L4_head);

   cout << "max num:" << MaxNodeVal(L4_head) << endl;
   cout << "==============================" << endl << endl;


   cout << "==============7================" << endl;
   L4 = new ListNode(1);
   L4_head = L4;

   EndInsertEles(L4, {3, 3, 5, 5, 7});

   cout << "start:";
   Print(L4_head);

   cout << "reverse:";
   Print(reverseList2(L4_head));
   cout << "==============================" << endl << endl;


   cout << "==============10================" << endl;
   SqList *list = new SqList();
   list->addEles({6, 555, 55, 6, 5, 55, 555, 6});
   cout << "before"; list->printList();
   DeleteItemByItem(list, 6);
   cout << "after"; list->printList();
   list->~SqList();
   cout << "==============================" << endl << endl;

   return 0;
}

// ==1==
// 将两个递增的有序链表合并为一个递增的有序链表。
//要求结果链表仍使用原来两个链表的存储空间，
//不另外占用其他的存储空间。表中不允许有重复的数据。
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    } else if (l1 -> val > l2 -> val) {
        l2->next = mergeTwoLists(l1, l2 -> next);
        return l2;
    } else {
        l1->next = mergeTwoLists(l1 -> next, l2);
        return l1;
    }
}

ListNode* mergeTwoLists2(ListNode *l1, ListNode *l2)
{
    ListNode *preNode = new ListNode(-1);
    ListNode *t = preNode;

    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1 -> val < l2 -> val) {
            preNode -> next = l1;
            l1 = l1 -> next;
        } else {
            preNode -> next = l2;
            l2 = l2 -> next;
        }
        preNode = preNode -> next;
    }
    preNode -> next = l1 == nullptr ? l2 : l1;
    return t -> next;
}

/*
===2===
将两个非递减的有序链表合并为一个非递增的有序链表。
要求结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间。表中允许有重复的数据。
*/
ListNode* reverseList(ListNode *L);
ListNode* mergeAndChangeLists(ListNode *l1, ListNode *l2)
{
    ListNode *preNode = new ListNode(-1);
    ListNode *headNode = preNode;

    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1 -> val < l2 -> val) 
        {
            preNode -> next = l1;
            l1 = l1 -> next;
        } 
        else
        {
            preNode -> next = l2;
            l2 = l2 -> next;
        }
        preNode = preNode -> next;
    }

    preNode -> next = l1 == nullptr ? l2 : l1;
    
    ListNode *ans = new ListNode(-1);
    
    ans = reverseList(headNode -> next);

    return ans;
}

ListNode* reverseList(ListNode *L)
{
    ListNode *cur = L, *per = nullptr;

    while(cur -> next != nullptr)
    {
        ListNode *temp = cur -> next;
        cur -> next = per;
        per = cur;  
        cur = temp; 
    }
    return per;
}

/**
 * （5）设计算法将一个带头节点的单链表A分解为两个具有相同结构的链表B和C，
 * 其中B表的节点为A表中值小于0的节点，而C表的节点为A表中值大于0的节点
 * （链表A中的元素为非零整数，要求B、C表利用A表的节点）。
 */
void splitList(ListNode *oldNode, ListNode *&B, ListNode *&C)
{
    ListNode *headList = oldNode -> next;

// 初始化B和C的头节点和尾节点
    ListNode *BHead = new ListNode(0);  // 虚拟头节点
    ListNode *CTail = new ListNode(0);  // 虚拟头节点

    ListNode *Bper = BHead;
    ListNode *Cper = CTail;

    while(headList != nullptr)
    {
        ListNode *tmp = headList;
        if(headList -> val < 0) {
            Bper -> next = tmp;
            tmp -> next = nullptr; 
            Bper = Bper -> next;
        } else {
            Cper -> next = tmp;
            tmp -> next = nullptr; 
            Cper = Cper -> next;
        }
        headList = headList -> next;
    }

        // 移除虚拟头节点
    B = BHead->next;
    C = CTail->next;

        // 释放虚拟头节点内存
    delete BHead;
    delete CTail;

}

// （6）设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的节点。
int MaxNodeVal(ListNode *L)
{
    int temp = -1;
    while(L  != nullptr)
    {
        temp = temp > L -> val ? temp : L -> val;
        L = L -> next;
    }
    return temp;
}
/**
 * ===7===
 * 设计一个算法，将链表中所有节点的链接方向“原地”逆转，
 * 即要求仅利用原表的存储空间，换句话说，要求算法的空间复杂度为O(1)。
 */
ListNode* reverseList2(ListNode *L)
{
    ListNode *cur = L, *per = nullptr;

    while(cur != nullptr)
    {
        ListNode *temp = cur -> next;
        cur -> next = per;
        per = cur;
        cur = temp;
    }

    return per;
}

/**
 * (10）已知长度为n的线性表A采用顺序存储结构，请设计一个时间复杂度为O（n)、空间复杂度为O（1）的算法，
 * 该算法可删除线性表中所有值为item的数据元素。
 */
void DeleteItemByItem(SqList *list, int ele)
{

    for (int i = list->getSize() - 1; i >= 0 ;i--) {
        if (list->getElement(i) == ele) 
            list->removeElement(i);
    }

}
