#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num_1[] = {1,2,3,4,5};
vector<int> num_2(num_1 + 2,num_1 + 10);

int main(){
    
    for(auto i = begin(num_2);i != end(num_2);i++){
        cout << *i << endl;
    }
    
    /* auto num_3 = num_1; */

    for(auto n : num_2){
        cout << n << endl;
    }

    return 0;
}
