/**
 *  ���ò���
 *  
 */
#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int  * p = &a;
    // ��������
    int &pp = *p;

    // ���ÿ����ǿյ���
    // ����û����
    int * p1 = nullptr;
    int &pp1 = *p1;
    // ��ʹ�õ�ʱ�� ��ָ������û�б���
    cout << "intָ�������" << pp << "��ָ�������" << endl << pp1 << endl;
    return 0;
}
