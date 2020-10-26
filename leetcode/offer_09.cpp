//
// Created by zzy on 2020/10/26.
//
//用两个栈实现队列

#include <iostream>
#include <stack>
using namespace std;
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
class CQueue {
    stack<int> stack_1,stack_2;
public:
    CQueue() {
        while(!stack_1.empty()){
            stack_1.pop();
        }
        while(!stack_2.empty()){
            stack_2.pop();
        }
    }

    void appendTail(int value) {
        stack_1.push(value);
    }

    int deleteHead() {
        if(stack_2.empty()){
            while(!stack_1.empty()){
                stack_2.push((stack_1.top()));
                stack_1.pop();
            }
        }

        if(stack_2.empty()){
            return -1;
        }else {
            int delete_t = stack_2.top();
            stack_2.pop();
            return delete_t;
        }
    }
};
int main(){
    return 0;
}
