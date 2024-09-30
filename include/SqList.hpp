#include <iostream>
#include <stdexcept>
#include <initializer_list>

#ifndef SQ_LIST_HPP
#define SQ_LIST_HPP
const int MAX_LENGTH = 30;
using namespace std;

typedef struct SqList {
    private :
        int *Eles;
        int size;
    public :
    SqList() {
        size = 0;
        Eles = new int[MAX_LENGTH];
    }
    SqList(int val) {
        size = 1;
        Eles = new int[MAX_LENGTH];
        Eles[0] = val;
    }

    // 析构函数
    ~SqList() {
        delete[] Eles;
    }

    void addEle(int val) 
    {
        if (size >= MAX_LENGTH) {
            throw runtime_error("the list is full");
        }
        Eles[size++] = val;
    }

    void addEles(initializer_list<int> list) {
        for (auto item : list) {
            addEle(item);
        }
    }

    // 删除指定位置的元素
    void removeElement(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < size - 1; ++i) {
            Eles[i] = Eles[i + 1];
        }
        --size;
    }

    // 获取指定位置的元素
    int getElement(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return Eles[index];
    }

    // 获取列表的长度
    int getSize() const{
        return size;
    }

    // 打印列表内容
    void printList() const {
        std::cout << "List contents: ";
        cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << Eles[i] ;
            if (i < size - 1) cout <<", ";

        }
        std::cout << "]" << std::endl;
    }

    // 指定位置插入元素
    void insertEleByIndex(int index, int val) {
        if (index < 0 || index >= size - 1) {
            throw std::out_of_range("Index out of bounds");
        } 
        // [1 2 3 #] index = 2 
        for (int i = size + 1; i > index; i--) {
            Eles[i - 1] = Eles[i];
        }
        Eles[index] = val;
        size++;
    }
} SqList;

#endif
