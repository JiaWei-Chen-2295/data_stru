#include <iostream>

int change(int **p){
    int a = 5;
    *p = &a;
    return 0;
}
int main()
{
    int b = 9;
    int *p = &b;
    
    std::cout << *p << std::endl;
    change(&p);
    std::cout << *p << std::endl;
}
