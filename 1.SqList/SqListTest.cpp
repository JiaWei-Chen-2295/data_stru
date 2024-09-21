#include <iostream>

#include "SqList.h"
#include "Box.h"
#include "Status.h"

using namespace std;


SqList* newSqList()
{
    char first_box_name[BOX_NAME_MAX_SIZE];
    cout << "请输入列表中第一个盒子名字：" << endl;
    cin >> first_box_name;
    Box *first_box = CreateBox(1, first_box_name);
    SqList *L = createSqList(first_box);
    return L;
}

Status addBox(SqList *L)
{
    char box_name[BOX_NAME_MAX_SIZE];
    cout << "请输入列表中盒子名字：" << endl;
    cin >> box_name;
    return AddElement(*L, CreateBox(L->length + 1, box_name));
}
int main() 
{
    int choice;
    SqList *L = nullptr;
    while(true)
    {   
        cout << "================================" << endl;
        cout << "请输入操作：" << endl;
        cout << "1. 创建一个盒子列表" << endl;
        cout << "2. 销毁当前盒子列表" << endl;
        cout << "3. 添加一个盒子" << endl;
        cout << "4. 删除一个盒子" << endl;
        cout << "5. 查找盒子" << endl;
        cout << "6. 打印盒子列表" << endl;
        cout << "7. 退出" << endl;
        cout << "8. 指定位置增加元素" << endl;
        cout << "================================" << endl;
        
        
        
        
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                L = newSqList();
                system("cls");
                break;
            case 2:
                if (L == nullptr) {
                    cout << "当前没有盒子列表" << endl;
                    break;
                }
                DestroyList(L);
                system("cls");
                break;
            case 3:
                if (L == nullptr) {
                    cout << "当前没有盒子列表" << endl;
                    break;
                }
                if (!addBox(L)) {
                    cout << "添加盒子成功" << endl;
                } else {
                    cout << "添加盒子失败" << endl;
                }
                break;
            case 4:
                if (L == nullptr) {
                    cout << "当前没有盒子列表" << endl;
                    break;
                }
                cout << "请输入要删除的盒子序号：" << endl;
                int index;
                cin >> index;
                if (!DeleteElement(*L, index)) {
                    cout << "删除盒子成功" << endl;
                } else {
                    cout << "删除盒子失败" << endl;
                }
                break;
            case 5:
                if (L == nullptr) {
                    cout << "当前没有盒子列表" << endl;
                    break;
                }
                cout << "请输入要查找的盒子名字：" << endl;
                char box_name[BOX_NAME_MAX_SIZE];
                cin >> box_name;
                cout << "盒子序号为：" << FindElement(*L, box_name) << endl;
                break;
            case 6:
                if (L == nullptr) {
                    cout << "当前没有盒子列表" << endl;
                    break;
                }
                PrintList(*L);
                break;
            case 7:
                cin >> choice;
                return 0;
            case 8:
                if (L == nullptr) {
                    cout << "当前没有盒子列表" << endl;
                    break;
                }
                cout << "请输入要插入的盒子序号：" << endl;
                int insert_index;
                cin >> insert_index;
                cout << "请输入要插入的盒子名字：" << endl;
                char insert_box_name[BOX_NAME_MAX_SIZE];
                cin >> insert_box_name;
                if (!ElementInsert(*L, CreateBox(insert_index, insert_box_name), insert_index)) {
                    cout << "插入盒子成功" << endl;
                } else {
                    cout << "插入盒子失败" << endl;
                }
                break;
                
        }
        
    }
    return 0;
}

