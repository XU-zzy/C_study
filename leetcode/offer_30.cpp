class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data, help;
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        // 如果x是data和help的第一个元素，或者x小于等于help的最小元素，入栈
        if(help.empty() || x <= help.top()) help.push(x);
        if(x > help.top())
        {
            // 如果x大于help的最小元素，向help中再压入一遍该最小元素，保持两个栈元素个数相等
            // 比如data里现在有3，help里现在也有3，data里压入一个4，那么help里压入一个3
            // 这样如果把data的4弹出，我们同步把help的3也弹出
            int temp = help.top();
            help.push(temp);
        }
    }
    
    void pop() {
        if(!data.empty() && !help.empty())
        {
            data.pop();
            help.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return help.top();
    }
};


