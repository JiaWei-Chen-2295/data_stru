/**
 * vector 是 cpp 动态容器 基于数组
 * 允许动态删除和增加元素
 * 
 */
#include <iostream>
#include <vector>

using namespace std;
int main() {
    // 新建容器
    vector<int> myFirstVector;

    // 检验是否为空
    // 1 true
    cout << "this vector is  " << myFirstVector.empty() << endl;

    // 向容器末尾添加元素
    myFirstVector.push_back(1);
    myFirstVector.push_back(3);
    myFirstVector.push_back(8);
    myFirstVector.push_back(9);
    myFirstVector.push_back(45);
    myFirstVector.push_back(45);

    // 检验是否为空
    // 0 false
    cout << "this vector is  " << myFirstVector.empty() << endl;


    auto i =  myFirstVector.begin();
    
    
    for (auto num : myFirstVector) {
        cout << num << endl;
    }

    auto num = 5;
    auto name = 'c';
    char name[] = {'H', 'A', 'H', 'A', 'H', 'A'};
    return 0;
}