#include <iostream>
// 该数据结构定义请参考 LinkStack.hpp 文件
#include <LinkStack.hpp>

using namespace std;
int main()
{
    LinkStack *l1 = new LinkStack();

    cout << "success push num :" << push(l1, 5) << " the stack top is:" << peek(l1) <<endl;
    cout << "success push num :" << push(l1, 2) << " the stack top is:" << peek(l1) <<endl;
    cout << "success push num :" << push(l1, 5) << " the stack top is:" << peek(l1) <<endl;
    cout << "success push num :" << push(l1, 5) << " the stack top is:" << peek(l1) <<endl;

    cout << "now pop num is:" << pop(l1) << " the stack top is:" << peek(l1) << endl;
    cout << "now pop num is:" << pop(l1) << " the stack top is:" << peek(l1) << endl;
    cout << "now pop num is:" << pop(l1) << " the stack top is:" << peek(l1) << endl;
    cout << "now pop num is:" << pop(l1) << " the stack top is:" << peek(l1) << endl;

    return 0;
}