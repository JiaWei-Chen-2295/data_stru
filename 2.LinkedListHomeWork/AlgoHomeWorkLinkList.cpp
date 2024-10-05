/**
数据结构第二章
课后习题
2.算法设计题
（
*/
#include <iostream>
#include <SimpleListNode.hpp>
#include <SqList.hpp>
#include <Status.h>
#include <DoublyListNode.hpp>

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
 * ===3===
 * 已知两个链表A和B分别表示两个集合，
 * 其元素递增排列。请设计一个算法，用于求出A与B的交集，
 * 并将结果存放在A链表中。
 */
void Intersection(ListNode **a, ListNode *b);

/**
 * ===4===
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。
 * 请设计算法求出两个集合A和B的差集（仅由在A中出现而不在B中出现的元素所构成的集合），
 * 并将结果以同样的形式存储，同时返回该集合的元素个数。
 */
int Subset(ListNode *list1, ListNode *list2, ListNode **results);

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
/**（8）设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素
 * （mink和maxk是给定的两个参数，其值可以和表中的元素相同，
 * 也可以不同）。
 */
void deleteNodeByItem(int mink, int maxk, ListNode **head);
void myDeleteNodeByItem(int mink, int maxk, ListNode **head);
/**
 * ===9===
 * 已知p指向双向循环链表中的一个节点，其节点结构为data、prev、next这3个域，
 * 设计算法change(p)，交换p所指向的节点及其前驱节点的顺序。
 */
void change(DoublyListNode *p);
/**
 * (10）已知长度为n的线性表A采用顺序存储结构，请设计一个时间复杂度为O（n)
 * 、空间复杂度为O（1）的算法，
 * 该算法可删除线性表中所有值为item的数据元素。
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

cout << "==============3================" << endl;
   L4 = new ListNode(1);
   L4_head = L4;

   EndInsertEles(L4, {3, 3, 5, 5, 7, 8});

   cout << "first:";
   Print(L4_head);

   L5 = new ListNode(1);
   L5_head = L5;

   EndInsertEles(L5, {2, 3, 4, 4, 7, 8, 8});

   cout << "second:";
   Print(L5_head);

   Intersection(&L4_head, L5_head);

   cout << "intersection:" ;
   Print(L4_head);
   cout << "==============================" << endl << endl;

   cout << "==============4================" << endl;
   L4 = new ListNode(1);
   L4_head = L4;

   EndInsertEles(L4, {1, 2, 3, 4, 5, 6});

   cout << "first:";
   Print(L4_head);

   L5 = new ListNode(1);
   L5_head = L5;

   EndInsertEles(L5, {2, 4, 5});

   cout << "second:";
   Print(L5_head);

   ListNode *res = new ListNode(0);

   int r = Subset(L4_head, L5_head, &res);

   cout << "intersection:" << endl << r << endl ;
   Print(res);
   cout << "==============================" << endl << endl;

   cout << "==============5================" << endl;
   L4 = new ListNode(1);
   L4_head = L4;

   EndInsertEles(L4, {1, -3, 3, -8, 5, -7, 90});
   
   cout << "start:";Print(L4_head->next);
   ListNode *L6 = new ListNode(0); 
   ListNode *L7 = new ListNode(0); 
   splitList(L4, L6, L7);
   cout << "B:" ;Print(L6);
   cout << "C:" ;Print(L7);
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
   cout << "===============================" << endl << endl;

cout << "===============8===============" << endl;
   L4 = new ListNode(0);
   L4_head = L4;

   EndInsertEles(L4, {130, 150, 170, 190, 200, 299, 300, 500});

   cout << "start: " << endl;
   Print(L4_head -> next);

   cout << "deleted: " << endl;
   deleteNodeByItem(160, 300, &L4_head);
   Print(L4_head -> next);
   cout << "==============================" << endl << endl;

   cout << "===============8===============" << endl;
   L4 = new ListNode(0);
   L4_head = L4;

   EndInsertEles(L4, {130, 150, 170, 190, 200, 299, 300, 500});

   cout << "start: " << endl;
   Print(L4_head -> next);

   cout << "deleted: " << endl;
   myDeleteNodeByItem(160, 300, &L4_head);
   Print(L4_head -> next);
   cout << "==============================" << endl << endl;

   cout << "==============9================" << endl;
   DoublyListNode *L8 = new DoublyListNode(0);
   DoublyListNode *head = L8;
   InsertEles(L8, {1, 2, 3});
   cout << "before change" << endl;
   Print(head -> next);

   change(L8);

   cout << "after change" << endl;
   Print(head -> next);

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
 * ===3===
 * 已知两个链表A和B分别表示两个集合，
 * 其元素递增排列。请设计一个算法，用于求出A与B的交集，
 * 并将结果存放在A链表中。
 */
void Intersection(ListNode **list1, ListNode *list2)
{
    ListNode *a = *list1;
    ListNode *b = list2;

    ListNode *tmp = new ListNode(0);
    ListNode *t_head = tmp;

    while (a != nullptr && b != nullptr)
    {
        if (a -> val == b -> val)
        {
            tmp -> next = a;
            tmp = tmp -> next;
            a = a -> next;
            b = b -> next;
        } else if (a -> val > b -> val) {
            b = b -> next;
        } else {
            a = a -> next;
        }
    }

    *list1 = t_head -> next;
}

/**
 * ===4===
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。
 * 请设计算法求出两个集合A和B的差集（仅由在A中出现而不在B中出现的元素所构成的集合），
 * 并将结果以同样的形式存储，同时返回该集合的元素个数。
 */
// [1, 2, 3] [2, 3]
int Subset(ListNode *list1, ListNode *list2, ListNode **results)
{
int count = 0;
    ListNode dummyHead(0); // 使用哑节点简化代码
    ListNode *res = &dummyHead;
    ListNode *l1 = list1;
    ListNode *l2 = list2;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            res->next = l1;
            res = res->next;
            l1 = l1->next;
            count++;
        } else if (l1->val > l2->val) {
            l2 = l2->next;
        } else { // 相等时跳过
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    // 将剩余部分加入结果链表
    while (l1 != nullptr) {
        res->next = l1;
        res = res->next;
        l1 = l1->next;
        count++;
    }
    *results = dummyHead.next; // 返回结果链表头
    return count;
}

/**
 * ===5===
 * 设计算法将一个带头节点的单链表A分解为两个具有相同结构的链表B和C，
 * 其中B表的节点为A表中值小于0的节点，而C表的节点为A表中值大于0的节点
 * （链表A中的元素为非零整数，要求B、C表利用A表的节点）。
 */
void splitList(ListNode *oldNode, ListNode *&B, ListNode *&C)
{
    // 初始化B和C的头节点和尾节点
    ListNode *Bhead = nullptr;
    ListNode *Btail = nullptr;
    ListNode *Chead = nullptr;
    ListNode *Ctail = nullptr;

    ListNode *headList = oldNode -> next;

    while (headList != nullptr)
    {
        ListNode *tmp = headList;
        if (headList -> val < 0)
        {
            if (Bhead == nullptr) {
                Bhead = tmp;
                Btail = tmp;
            } else {
                Btail -> next = tmp;
                Btail = tmp;
            }
        } else
        {
            if (Chead == nullptr){
                Chead = tmp;
                Ctail = tmp;
            } else {
                Ctail -> next = tmp;
                Ctail = tmp;
            }
        }
        headList = headList -> next;
        tmp -> next = nullptr; // 断开当前节点与下一个节点的连接
    }

    // 更新B和C的头指针
    B = Bhead;
    C = Chead;
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
 * ===8=== 
 * 设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素
 * （mink和maxk是给定的两个参数，其值可以和表中的元素相同，
 * 也可以不同）。
 * @param mink 下界限
 * @param maxk 上界限
 * @return None
 */
void deleteNodeByItem(int mink, int maxk, ListNode **head)
{
    // 处理特殊情况：如果链表为空或者mink >= maxk，则不进行任何操作
    if (head == nullptr || *head == nullptr || mink >= maxk) {
        return;
    }

    ListNode *current = *head;
    ListNode *prev = nullptr;

    // 遍历链表，找到第一个大于等于mink的节点
    while (current != nullptr && current->val < mink) {
        prev = current;
        current = current->next;
    }

    // 删除值在[mink, maxk)范围内的节点
    while (current != nullptr && current->val < maxk) {
        ListNode *toDelete = current;
        current = current->next;
        delete toDelete; // 释放被删除节点的内存
    }

    // 如果prev为空，说明第一个大于等于mink的节点是头节点
    if (prev == nullptr) {
        *head = current; // 更新头指针
    } else {
        prev->next = current; // 连接剩余的链表
    }
}

void myDeleteNodeByItem(int mink, int maxk, ListNode **head)
{
    // 判断输入
    if (head == nullptr || *head == nullptr || mink >= maxk) return;

    ListNode *now = *head;
    ListNode *pre = nullptr;
    // 找到要删除的边界
    while (now != nullptr && now -> val < mink)
    {
        pre = now;
        now = now -> next;
    }

    //开删
    while (now != nullptr && now -> val < maxk)
    {
        ListNode *tmp = now;
        now = now -> next;
        delete tmp;
    }

    // 如果prev为空，说明第一个大于等于mink的节点是头节点
    if (pre == nullptr) {
        *head = now; // 更新头指针
    } else {
        pre->next = now; // 连接剩余的链表
    }
}

/**
 * ===9===
 * 已知p指向双向循环链表中的一个节点，其节点结构为data、prev、next这3个域，
 * 设计算法change(p)，交换p所指向的节点及其前驱节点的顺序。
 */
void change(DoublyListNode *p)
{
    if (p == nullptr || p->prev == p) return;  // 空链表或只有一个节点

    DoublyListNode *q = nullptr;
	q = p->prev;
	q -> prev -> next = p;//p的前驱的前驱之后继为p
 	p->prev=q->prev;//p的前驱指向其前驱的前驱。
 	q->next=p->next;//∥p的前驱的后继为p的后继。
 	q->prev=p;//p与其前驱交换
	p->next->prev=q;//p的后继的前驱指向原p的前驱
 	p->next=q;//p的后继指向其原来的前驱
 
}
/**
 * (10）已知长度为n的线性表A采用顺序存储结构，请设计一个时间复杂度为O（n)、
 * 空间复杂度为O（1）的算法，
 * 该算法可删除线性表中所有值为item的数据元素。
 */
void DeleteItemByItem(SqList *list, int ele)
{
    int count = 0;
    int start = 0;
    int end = list -> getSize() - 1;

    while (start <= end) 
    {
        if (list->getElement(start) == ele) 
        {
            count++;
            if (list->getElement(end) != ele)
            {    
                int t = list->setEle(start, list->getElement(end));       
                list->setEle(end, t);
                end--;
            } 
            else
            {
                end--;
                start--;
            }       
        }
        start++;
    }
    while (count > 0) {
        list -> removeElement(list->getSize() - 1);
        count--;
    }
    
}