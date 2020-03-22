#include <iostream>
#include<vector>

using std:: cout;
using std:: endl;
using std:: vector;

int main()
{
    vector<int> v(10,8);

    vector<int>::iterator iter = v.begin();

    *iter = 9;
    iter++;
    *iter = 0;

    for(vector<int>::iterator i = v.begin();i != v.end();++i)
        cout << " : " << *i << endl;
    return 0;
}

