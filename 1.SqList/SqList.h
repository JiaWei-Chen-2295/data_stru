#ifndef SQLIST_H
#define SQLIST_H

#include <iostream>
#include "Status.h"
#include "Box.h"
#define MAX_SIZE 100



typedef struct SqList
{
    Box *data[MAX_SIZE];
    int length;
} SqList;

SqList* createSqList(Box *data);
Status InitList(SqList &L, Box *data);
Status DestroyList(SqList *L);
Status AddElement(SqList &L, Box *data);
Status DeleteElement(SqList &L, int index);
void PrintList(SqList &L);
int FindElement(SqList &L, char box_name[]);
bool isEmpty(SqList &L);

SqList* createSqList(Box *data) 
{
    SqList *list = new SqList;

    if(list != nullptr) 
    {
        if(InitList(*list, data) == -1) 
        {
            delete list;
            list = nullptr;
            std::cout << "Init SqList Fail" << std::endl;
        }
    }        
    return list;
}

Status InitList(SqList &L, Box *data)
{
    L.length = 1;
    if (data != nullptr)
    {
        L.data[0] = data;
    } else
    {
        return ERROR;
    }
    return OK;
}

Status DestroyList(SqList *L)
{
    for (int i = 0; i < L -> length; i++)
    {
        DestroyBox(L -> data[i]);
    }
    delete[] L;
    if(L != nullptr) return ERROR;
    return OK;
}

Status AddElement(SqList &L, Box *data)
{
    if (L.length >= MAX_SIZE)
    {
        return ERROR;
    }
    L.data[L.length++] = data;
    return OK;
}

Status DeleteElement(SqList &L, int index)
{
    if (index < 0 || index >= L.length)
    {
        return ERROR;
    }
    for (int j = index - 1; j < L.length -1; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    // [1] [2] [3] [4] 删除 3 --> index = 3
    // [1] [2] [3] [4]
    //          ^   ^
    //          j |j + 1
    L.length--;
    return OK;
}

void PrintList(SqList &L)
{   
    if(isEmpty(L)) std::cout << "无内容" << std::endl;
    
    for (int i = 0; i < L.length; i++)
    {
        std::cout << i << "====>" << L.data[i]->name << std::endl;
        
    }
}

int FindElement(SqList &L, char box_name[])
{
    for (int i = 0; i < L.length; i++)
    {
        if (strcmp(L.data[i]->name, box_name) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool isEmpty(SqList &L)
{
    return L.length == 0;
}

#endif

