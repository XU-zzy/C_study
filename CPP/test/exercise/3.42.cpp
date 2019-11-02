#include <iostream>
#include<vector>
#include<ctime>

using namespace std;

vector<int> vint;

int main()
{
    srand((unsigned)time(NULL));
    int sz = 10;
    
    cout << "vector对象内容:" << endl;
    
    for(int i = 0;i < sz;i++){
        vint.push_back(rand()%100);      //100以内随机数
        cout << vint[i] << " ";
    }
    
    cout << endl;

    cout << "数组内的内容:" << endl;

    int a[vint.size()];
    auto it = vint.begin();
    for(auto &val : a){
        val = *it;
        cout << val << " ";
        it++;
    }

    cout << endl;

    return 0;
}

