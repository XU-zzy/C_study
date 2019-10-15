#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> num;

int main(){
    
    for(int i = 0;i < 100;i++){
        num.push_back(i);
    }
    
    int ans;
    cin >> ans;

    auto be = num.cbegin(),end = num.cend();
    auto mid = num.cbegin() + (num.cend() - num.cbegin())/2;

    while(mid != num.cend() && *mid != ans){
        if(ans > *mid){
            be = mid + 1;
        }else{
            end = mid;
        }
        
        mid = be + (end - be)/2;
        cout << *be << " " << *end << " " << *mid << endl;
    }

    cout << "final:" << *mid << endl;

    return 0;
}

