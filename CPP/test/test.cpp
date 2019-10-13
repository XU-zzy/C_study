#include <iostream>
using namespace std;

int i = 1;
int main()
{
    int i = 0;
    int &r_1 = i;
    const int &r_2 = i;
    cout << i << r_1 << r_2 << endl;
    
    r_1 = 1;

    cout << i << r_1 << r_2 << endl;

    return 0;
}

