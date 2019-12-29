#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num;
    while(n--){
        int count = 0;
        cin >> num;
        if(num & 1){
            count++;
        }
        while(num >>= 1){
            if(num & 1){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

