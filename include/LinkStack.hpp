#include <SimpleListNode.hpp>

#ifndef LINK_STACK_H
#define LINK_STACK_H

const int MAX_LINK_STACK_NUMS = 20;

typedef struct LinkStack
{
    int size;
    ListNode *item_head;// 头节点作为栈顶

    LinkStack():size(0), item_head(nullptr){}
    LinkStack(int val):size(1), item_head(new ListNode(val)){}
} LinkStack;

/**push
 * 压栈
 * @param s 指向一个链表栈的指针
 * @param v 需要插入的值
 * @return 返回参数`v`的值 如果为 -1 则插入失败
*/
int push(LinkStack *s, int v)
{
    if (s -> size >= MAX_LINK_STACK_NUMS) return -1;

    if (s -> size == 0)
    {
        s -> item_head = new ListNode(v);   
    } else {
        // 在头部插入新节点
        ListNode *newNode = new ListNode(v);
        newNode -> next = s -> item_head;
        s -> item_head = newNode;
    }
    s -> size++;
    return v;
}

/**
 * pop
 * 出栈
 * @param s 指向一个链表栈的指针
 * @return 返回栈顶元素的值，如果栈为空则返回 -1
 */
int pop(LinkStack *s)
{
    if (s -> size == 0) return -1;

    // 记录栈顶节点
    ListNode *deletedNode = s -> item_head;
    int t_num = deletedNode -> val;

    // 如果只有一个节点，则清空整个结构
    if (s -> size == 1)
    {
        s -> item_head = nullptr;
    }
    else
    {
        // 找到第二个节点作为新的头部
        s -> item_head = s -> item_head -> next;
    }

    s -> size--;
    delete deletedNode; // 释放旧头部节点

    return t_num;
}
/**
 * 获取栈顶元素的值
 * @param s 指向一个链表栈的指针
 * @return 返回栈顶元素的值，如果栈为空则返回 -1
 */
int peek(LinkStack *s)
{
    if (s -> size == 0) return -1;
    return s -> item_head -> val;
}
#endif