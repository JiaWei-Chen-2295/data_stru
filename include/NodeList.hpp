#include "Status.h"
#include <iostream>

#ifndef NODE_LIST_H
#define NODE_LIST_H

typedef struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int v):val(v), next(nullptr), prev(nullptr) {}
}Node;

typedef struct NodeList {
    int size;
    Node *head;
    Node *last;
    NodeList(): size(0), head(nullptr), last(nullptr) {}
} NodeList, *NL;

// 初始化
Status InitList(NodeList *&NL)
{
    NL = new NodeList();
    if (NL == nullptr)
    {
        return ERROR;
    }
    
    return OK;
}

// 遍历打印
void PrintListVal(NodeList &L)
{
    int index = 0;
    Node *p = L.head;
    std::cout << "[" ;
    while(p != nullptr)
    {
        index++;
        std::cout << p -> val;
        if (index < L.size) std::cout << ", ";
        p = p -> next;
    }
    std::cout << "]" << std::endl;
    std::cout << "While count is " << index << std::endl;
}
// 头插
Status HeadListInsert(NodeList *L, int val)
{
    if (L == nullptr) return ERROR;
    
    // init node
    Node *node = new Node(val);
        
    node->next = L->head;
    node->prev = nullptr;
    
    if (L->head != nullptr) L->head->prev = node;
    
    L->head = node;
    
    if (L->size == 0)L->last = node;
        
    L->size++;
    return OK;
}

// 插入
Status ListInsert(NodeList *L,int index, int val)
{
    // check input
    if (L == nullptr || index < 0 || index > L -> size) return ERROR;
    
    // prepare 
    Node *p = L -> head;  
    int n = 0; 
    Node *node = new Node(val);

    if (index == 0)
    {
        HeadListInsert(L, val);
    }
    
    // NULL is false
    while(p != nullptr && n < index - 1)
    {
        n++;
        p = p -> next;  
    }
    
    if (p == nullptr || n < index - 1) return ERROR;
    
    node -> next = p -> next;
    node -> prev = p;
    if (p -> next != nullptr)
        p -> next -> prev = node;
    p -> next = node;
    
    if(index == L -> size)
            L -> last = node;
             
    L -> size++;
    return OK;

}

// 尾插
Status EndListInsert(NodeList *L, int val)
{
    if (L == nullptr) return ERROR;
    
    // init node
    Node *node = new Node(val);
        
    if(node == nullptr) return ERROR;

    if (L -> size == 0) 
    {  
        // modify list
        L -> head = node;
        L -> last = node;
        L -> size++;
        
        return OK;
    }
    // last add node 
    node -> prev = L -> last;
    L -> last -> next = node;
    L -> last = node;
    
    L -> size++;
    
    return OK; 
}

Node* GetNode(NodeList *L, int index)
{
    if (L == nullptr || index < 0 || index >= L -> size) return nullptr;
    
    Node *p = L -> head;
    int n = 0;

    while (p)
    {
        n++;
        p = p -> next;
        if (n == index) return p;
    }
    return nullptr;
}

// 时间复杂度 O(n)
int FindNodeIndex(NodeList *L, int val)
{
    if (L == nullptr || L -> size <= 0) return ERROR; 
    
    // prepare
    Node *p = L -> head;
    int n = 0;
    
    while(p)
    {
        n++;
        if (p -> val == val) return n;
        p = p -> next;
    }
    return ERROR; 
}

// delete
Status DeleteNode(NodeList *L, int index)
{
    if (L == nullptr || index < 0 || index > L -> size) return ERROR;
    
    Node *p = L -> head;
    int n = 0;
    int len = L -> size;

    while(p)
    {
        n++;
        if (n == index)
        {
            if (n == 1) {  
                L->head = p->next;
                
                if (L->head != nullptr)
                    L->head->prev = nullptr;
                    
            } else if (n == len) {  
                
                L->last = p->prev;
                if (L->last != nullptr)
                    L->last->next = nullptr;
                std::cout << "delete last node"<< L -> last -> val << std::endl;
                    
            } else {  // delete middle
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }

            delete p;  // 释放内存
            L->size--;
            return OK;
        }

        p = p -> next;
    }

}
#endif