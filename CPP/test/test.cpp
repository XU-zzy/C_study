#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str_1,str_t;
    cin >> str_1;
    for(auto c : str_1){
        if(!ispunct(c)){
            cout << c;
        }
    }

    return 0;
}
