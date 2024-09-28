/**
 *  引用测试
 *  
 */
#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int  * p = &a;
    // 创建引用
    int &pp = *p;

    // 引用可以是空的吗？
    // 编译没问题
    int * p1 = nullptr;
    int &pp1 = *p1;
    // 在使用的时候 空指针引用没有报错
    cout << "int指针的引用" << pp << "空指针的引用" << endl << pp1 << endl;
    return 0;
}
