#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> num(100);
int main(){
    /* for(int i = 0;i < 100;i++) */
        /* num.push_back(i); */
    fill(num.begin(),num.end(),1);
    int val;
    cin >> val;
    auto result = find(num.cbegin(),num.cend(),val);
    cout << "The value " << val  << (result == num.cend() ? " is not present" : " is present" ) << endl;
    cout << accumulate(num.cbegin(),num.cend(),50) << endl;
    return 0;
}
