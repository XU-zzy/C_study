#include <iostream>
using namespace std;

int main()
{
    unsigned u = 10,u2 = 42;
    int i = 10,i2 = 42;
    cout << "unsigned u = 10,u2 = 42\n" << "int i = 10,i2 = 42\n" << endl;
    
    cout << "1\v2\v" << "3\v" << endl;
    
    cout << "u-u2:" << u-u2 << endl;
    cout << "i2-i:" << i2-i << endl;
    cout << "i-i2:" << i-i2 << endl;
    cout << "i-u:" << i-u << endl;
    cout << "u-i:" << u-i << endl;
    return 0;
}

