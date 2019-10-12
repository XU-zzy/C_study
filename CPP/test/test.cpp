#include <iostream>
using namespace std;

int i = 1;
int main()
{
    int a = 0;
    cout << i << a << endl;
    int i = 0;
    cout << i << a << endl;
    
    cout << ::i << a << endl;
    return 0;
}

