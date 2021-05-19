//暴力
class MaxQueue {
    int q[20000];
    int begin = 0, end = 0;
public:
    MaxQueue() {
    }
    
    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; ++i)
            ans = max(ans, q[i]);
        return ans;
    }
    
    void push_back(int value) {
        q[end++] = value;
    }
    
    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++];
    }
};


///////////////////////////////////////////////////////////
//双端
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};
