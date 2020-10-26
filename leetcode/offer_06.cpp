//
// Created by zzy on 2020/10/26.
//
//从尾向头打印链表

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    //使用栈
    vector<int> reversePrint_1(ListNode* head) {
        if(head == nullptr){
            return vector<int>(0);
        }
        stack<int>  st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    //递归
    vector<int> reversePrint_2(ListNode* head){
        if(head == nullptr){
            return vector<int>(0);
        }
        reversePrint_2(head->next);
        ans.push_back(head->val);
        return ans;
    }
    //链表就地逆置
    vector<int> reversePrint_3(ListNode* head){
        if(head == nullptr){
            return vector<int>(0);
        }else if(head->next == nullptr){
            return vector<int>{1,head->val};
        }
        ListNode *rev = NULL,*t,*cur = head;
        while(cur != nullptr){
            //指针后移
            t = cur;
            //向后遍历
            cur = cur->next;
            //头插法类似
            t->next = rev;
            rev = t;
        }
        while(rev){
            ans.push_back(rev->val);
            rev = rev->next;
        }
        return ans;
    }

};

int main(){
    return 0;
}
