#define SQLIST_MAX_LENGTH 100

#include <iostream>
#include "Status.h"
#include "Box.h"
#include "SqList.h"

using namespace std;

int main()
{
    Box *box1 = CreateBox(1, "文具"); 
    Box *box2 = CreateBox(2, "衣服"); 
    Box *box3 = CreateBox(3, "书本"); 
    Box *box4 = CreateBox(4, "日用品"); 
    Box *box5 = CreateBox(5, "电器");

    // 使用数组
    Box *box[] = {box1, box2, box3, box4, box5};
    int box_length = sizeof(box) / sizeof(box[0]);
    cout << "box_length: " << box_length << endl;

    // 释放
    for(int i = 0; i < box_length; i++) {
        cout << box[i]->name << endl;
        DestroyBox(box[i]);
    }

    cout << "=============" << endl;

    // 使用我们写的线性表(顺序表)
    // 将值再次创建
    box1 = CreateBox(1, "文具"); 
    box2 = CreateBox(2, "衣服"); 
    box3 = CreateBox(3, "书本"); 
    box4 = CreateBox(4, "日用品"); 
    box5 = CreateBox(5, "电器");

    SqList *list = createSqList(box1);
    
    AddElement(*list, box2);
    AddElement(*list, box3);
    AddElement(*list, box4);
    AddElement(*list, box5);

    PrintList(*list);
    
    cout << "=============" << endl;

    DeleteElement(*list, 3);

    PrintList(*list);

    cout << "=============" << endl;
    cout << "查找" << endl;
    

    cout << "目前" << list->length << "个" << endl;
    char search_name[] = "电器";
    cout << search_name << "的下标是" << FindElement(*list, search_name)  << endl;

    cout << "=============" << endl;
    if(!DeleteElement(*list, 0)) {
        cout << "成功删除当前 0 为下标的元素" << endl;
    }
    if(!DeleteElement(*list, 0)) {
        cout << "成功删除当前 0 为下标的元素" << endl;
    }
    if(!DeleteElement(*list, 0)) {
        cout << "成功删除当前 0 为下标的元素" << endl;
    }
    if(!DeleteElement(*list, 0)) {
        cout << "成功删除当前 0 为下标的元素" << endl;
    }

    if(DeleteElement(*list, 0))
        cout << "出错了， 没有数据可以找了" << endl;
    
    PrintList(*list);
    cout << "当前数量" << list->length << endl;

    cout << "=============" << endl;
    cout << "销毁" << endl;
    if(DestroyList(list))
        cout << "销毁失败" << endl;
        
    return 0;
}