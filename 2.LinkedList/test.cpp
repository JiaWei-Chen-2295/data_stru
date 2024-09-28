#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode *next; //指针域
}LNode,*LinkList;
int InitList_L(LinkList &L)
{//构造一个空的单链表L
    L=new LNode;
    L->next=NULL;
    return OK;
}
int Input_L(LinkList &L)
{//链表的输入
/**************begin************/




    /**************end************/
}
int  Length_L(LinkList &L)
{//求链表的表长，即图书表中图书个数
/**************begin************/



    /**************end************/
}
int Output_L(LinkList L)
{//链表的输出
/**************begin************/



    /**************end************/
}
int main()
{
    LinkList L;        		//定义一个LinkList类型的变量L
    InitList_L(L);    		//初始化一个空的链表L
    Input_L(L);        		//输入链表数据
    Length_L(L);    		//求链表的表长并输出
    Output_L(L);    		//输出链表数据
    return 0;
}