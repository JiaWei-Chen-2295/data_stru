#include <DoublyListNode.hpp>

int main()
{
    DoublyListNode *list = new DoublyListNode(0);
    DoublyListNode *head = list;

    InsertEles(list, {1, 2, 2, 3, 45});
    Print(head);
    return 0;
}