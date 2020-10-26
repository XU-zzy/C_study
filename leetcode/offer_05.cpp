//
// Created by zzy on 2020/10/26.
//
//替换空格
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0,len = s.size();
        for(char c : s){
            if(c == ' '){
                ++count;
            }
        }
        s.resize(len + count * 2);

        int i = len - 1;int j = s.size() - 1;
        while(i != j){
            if(s[i] == ' ') {
                s[j] = '0';
                s[--j] = '2';
                s[--j] = '%';
                --j;
                --i;
                continue;
            } else{
                s[j] = s[i];
                --i;
                --j;
            }
        }
        return s;
//        cout << s << endl;
    }
};

int main(){
    Solution sol;
    string str = sol.replaceSpace("We are happy.");
    cout << str <<endl;
    return 0;
}