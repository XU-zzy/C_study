#include<iostream>
#include<vector>
#include<ctime>
/* #include<cstdlib> */

using namespace std;


int main()
{
    const int sz = 10;
    int a[sz];
    srand((unsigned)time(NULL));
    cout << "数组的内容：" << endl;

    //for遍历赋值数组
    for(auto &val : a){
        val = rand()%100;    //100以内随机数
        cout << val << " ";
    }
    cout << endl;

    vector<int> vint(begin(a),end(a));

    cout << "初始化后的vector:" << endl;

    for(auto &val : vint){
        cout << val << " ";
    }
    cout << endl;
    

    return 0;
}

