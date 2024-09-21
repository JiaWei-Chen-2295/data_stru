#include <iostream>

#include "SqList.h"
#include "Box.h"
#include "Status.h"

using namespace std;


SqList* newSqList()
{
    char first_box_name[BOX_NAME_MAX_SIZE];
    cout << "�������б��е�һ���������֣�" << endl;
    cin >> first_box_name;
    Box *first_box = CreateBox(1, first_box_name);
    SqList *L = createSqList(first_box);
    return L;
}

Status addBox(SqList *L)
{
    char box_name[BOX_NAME_MAX_SIZE];
    cout << "�������б��к������֣�" << endl;
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
        cout << "�����������" << endl;
        cout << "1. ����һ�������б�" << endl;
        cout << "2. ���ٵ�ǰ�����б�" << endl;
        cout << "3. ���һ������" << endl;
        cout << "4. ɾ��һ������" << endl;
        cout << "5. ���Һ���" << endl;
        cout << "6. ��ӡ�����б�" << endl;
        cout << "7. �˳�" << endl;
        cout << "8. ָ��λ������Ԫ��" << endl;
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
                    cout << "��ǰû�к����б�" << endl;
                    break;
                }
                DestroyList(L);
                system("cls");
                break;
            case 3:
                if (L == nullptr) {
                    cout << "��ǰû�к����б�" << endl;
                    break;
                }
                if (!addBox(L)) {
                    cout << "��Ӻ��ӳɹ�" << endl;
                } else {
                    cout << "��Ӻ���ʧ��" << endl;
                }
                break;
            case 4:
                if (L == nullptr) {
                    cout << "��ǰû�к����б�" << endl;
                    break;
                }
                cout << "������Ҫɾ���ĺ�����ţ�" << endl;
                int index;
                cin >> index;
                if (!DeleteElement(*L, index)) {
                    cout << "ɾ�����ӳɹ�" << endl;
                } else {
                    cout << "ɾ������ʧ��" << endl;
                }
                break;
            case 5:
                if (L == nullptr) {
                    cout << "��ǰû�к����б�" << endl;
                    break;
                }
                cout << "������Ҫ���ҵĺ������֣�" << endl;
                char box_name[BOX_NAME_MAX_SIZE];
                cin >> box_name;
                cout << "�������Ϊ��" << FindElement(*L, box_name) << endl;
                break;
            case 6:
                if (L == nullptr) {
                    cout << "��ǰû�к����б�" << endl;
                    break;
                }
                PrintList(*L);
                break;
            case 7:
                cin >> choice;
                return 0;
            case 8:
                if (L == nullptr) {
                    cout << "��ǰû�к����б�" << endl;
                    break;
                }
                cout << "������Ҫ����ĺ�����ţ�" << endl;
                int insert_index;
                cin >> insert_index;
                cout << "������Ҫ����ĺ������֣�" << endl;
                char insert_box_name[BOX_NAME_MAX_SIZE];
                cin >> insert_box_name;
                if (!ElementInsert(*L, CreateBox(insert_index, insert_box_name), insert_index)) {
                    cout << "������ӳɹ�" << endl;
                } else {
                    cout << "�������ʧ��" << endl;
                }
                break;
                
        }
        
    }
    return 0;
}

