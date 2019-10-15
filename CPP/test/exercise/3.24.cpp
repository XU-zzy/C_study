#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

int main()
{
    for(int i = 0;i < 10;i++){
        num.push_back(i);
    }

    auto a = num.begin();
    auto b = num.end()-1;
    for(;a < b;a++,b--){
        cout << *a + *b << endl;
    }

    return 0;
}

