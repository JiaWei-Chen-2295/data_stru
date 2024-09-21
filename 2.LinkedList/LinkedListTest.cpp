#include <iostream>

using namespace std;
int main(int argc,char* argv)
{
    cout << "Hello world!" << endl;
    cout << "argc: " << __argc << endl;
    for(int i = 0; i < __argc; i++)
    {
        cout << "argv[" << i << "]: " << __argv[i] << endl;
    }
    return 0;
}
