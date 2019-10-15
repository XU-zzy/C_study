#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ph;
int main()
{
    string n;
    for(int i = 0;i < 10;i++){
        cin >> n;
        for(auto &c : n){
            c = toupper(c);
        }
        ph.push_back(n);
    }
    
    for(int i = 0;i < 10;i++)
        cout << ph[i] << endl;
    

    return 0;
}
