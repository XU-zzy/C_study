//
// Created by zzy on 2020/10/26.
//
//斐波那契数列
//尽量不要用递归

#include <iostream>
using namespace std;

class Solution {
public:
    //递归
    int fib(int n) {
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }else{
            return fib(n-1) + fib(n-2);
        }
    }
    //非递归
    int fib_t(int n){
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }

        int i = 2;
        int rev = 1,now = 1;
        int ans = 1;
        while(i < n){
            ans = (rev + now)%1000000007;
            rev = now;
            now = ans;
            ++i;
        }
        return ans;
    }

    //也可以强行递归
    //使用递归时，递归次数多了就会出现很多重复计算的情况，
    //所以用HashMap将结果都存起来，每次计算前进行一次判断，运算过的话就直接取

};

int main(){

    Solution sol;

    cout << sol.fib_t(45) << endl;

    return 0;
}