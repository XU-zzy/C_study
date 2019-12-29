#include<iostream>
using namespace std;
int main(){
    int k;
    cin >> k;
    int n,m;
    int x,y;
    while(k--){
        cin >> n >> m;
        if((m - 2*n)%2 == 0 && n - (m - 2*n)/2 >= 0 && m > 2*n){
            y = (m - 2*n)/2;
            x = n - y;
            cout << x << " " << y << endl;
        }else{
            cout << "No answer" << endl;
        }
    }
}
