/**
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。
 * 请设计算法求出两个集合A和B的差集（仅由在A中出现而不在B中出现的元素所构成的集合），
 * 并将结果以同样的形式存储，同时返回该集合的元素个数。
 */
#include <iostream>
#include <SimpleListNode.hpp>

using namespace std;

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
            l2 = l2 -> next;
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
    res -> next = nullptr;
    *results = dummyHead.next; // 返回结果链表头
    return count;
}

int main()
{
    ListNode *a = new ListNode(1);
    EndInsertEles(a, {3, 5, 6, 8});

    ListNode *b = new ListNode(2);
    EndInsertEles(b, {4, 5, 7, 8});

    ListNode *r = new ListNode(0);

    cout << "num is " << Subset(a, b, &r) << endl;    
    // 1 3 6

    Print(r);

    system("pause");

    return 0;
}

