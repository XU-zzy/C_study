//int 类型不能使用empty()....

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> num(10);

int main(){

    for(int i = 0;i < 10;i++)
        cin >> num[i];

    cout << "output:" << endl;

    for(auto it = num.begin();it != num.end() ; it++){
        *it *= 2;
    }
    
    for(auto i = num.begin();i != num.end();i++)
        cout << *i << endl;

    return 0;
}

