#define SQLIST_MAX_LENGTH 100

#include <iostream>
#include "Status.h"
#include "Box.h"
#include "SqList.h"

using namespace std;

int main()
{
    Box *box1 = CreateBox(1, "�ľ�"); 
    Box *box2 = CreateBox(2, "�·�"); 
    Box *box3 = CreateBox(3, "�鱾"); 
    Box *box4 = CreateBox(4, "����Ʒ"); 
    Box *box5 = CreateBox(5, "����");

    // ʹ������
    Box *box[] = {box1, box2, box3, box4, box5};
    int box_length = sizeof(box) / sizeof(box[0]);
    cout << "box_length: " << box_length << endl;

    // �ͷ�
    for(int i = 0; i < box_length; i++) {
        cout << box[i]->name << endl;
        DestroyBox(box[i]);
    }

    cout << "=============" << endl;

    // ʹ������д�����Ա�(˳���)
    // ��ֵ�ٴδ���
    box1 = CreateBox(1, "�ľ�"); 
    box2 = CreateBox(2, "�·�"); 
    box3 = CreateBox(3, "�鱾"); 
    box4 = CreateBox(4, "����Ʒ"); 
    box5 = CreateBox(5, "����");

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
    cout << "����" << endl;
    

    cout << "Ŀǰ" << list->length << "��" << endl;
    char search_name[] = "����";
    cout << search_name << "���±���" << FindElement(*list, search_name)  << endl;

    cout << "=============" << endl;
    if(!DeleteElement(*list, 0)) {
        cout << "�ɹ�ɾ����ǰ 0 Ϊ�±��Ԫ��" << endl;
    }
    if(!DeleteElement(*list, 0)) {
        cout << "�ɹ�ɾ����ǰ 0 Ϊ�±��Ԫ��" << endl;
    }
    if(!DeleteElement(*list, 0)) {
        cout << "�ɹ�ɾ����ǰ 0 Ϊ�±��Ԫ��" << endl;
    }
    if(!DeleteElement(*list, 0)) {
        cout << "�ɹ�ɾ����ǰ 0 Ϊ�±��Ԫ��" << endl;
    }

    if(DeleteElement(*list, 0))
        cout << "�����ˣ� û�����ݿ�������" << endl;
    
    PrintList(*list);
    cout << "��ǰ����" << list->length << endl;

    cout << "=============" << endl;
    cout << "����" << endl;
    if(DestroyList(list))
        cout << "����ʧ��" << endl;
        
    return 0;
}