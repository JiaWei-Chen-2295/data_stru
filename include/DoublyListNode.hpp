#include <iostream>
#include <initializer_list>

using namespace std;

#ifndef DOUBLY_LISTNODE_HPP
#define DOUBLY_LISTNODE_HPP

typedef struct DoublyListNode {
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;

    DoublyListNode(int value) : val(value), next(this), prev(this) {}  // 初始化为循环链表
    DoublyListNode(int value, DoublyListNode *p) : val(value), next(this), prev(p) {}  // 初始化为循环链表
} DoublyListNode;

void addEle(DoublyListNode *head, int v)
{
    DoublyListNode *h = head;

    while (h->next != head)  // 循环到链表尾部
    {
        h = h->next;
    }

    DoublyListNode *node = new DoublyListNode(v, h);  // 新节点的prev指向h
    h->next = node;  // h的next指向新节点
    node->next = head;  // 新节点的next指向头节点
    head->prev = node;  // 头节点的prev指向新节点
}

void InsertEles(DoublyListNode *head, initializer_list<int> list)
{
    for (auto val : list)
    {
        addEle(head, val);
    }
}

void Print(DoublyListNode *head)
{
    DoublyListNode *h = head;
    cout << "[";

    do
    {
        cout << h->val << " ";
        h = h->next;
    } while (h != head);

    cout << "]" << endl;
}



#endif // DOUBLY_LISTNODE_HPP