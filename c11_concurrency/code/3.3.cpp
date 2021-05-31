//一个简易的线程安全堆栈
#include <exception>
#include <memory>
#include <mutex>
#include <stack>

//异常
struct empty_stack : std::exception
{
    const char *what() const throw()
    {
        return "empty stack!";
    };
};

template <typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack()
        : data(std::stack<int>()) {}
    threadsafe_stack(const threadsafe_stack &other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data; // 1 在构造函数体中的执行拷贝
    }

    threadsafe_stack &operator=(const threadsafe_stack &) = delete; //删除赋值操作

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    //使用智能指针
    //不仅可以避免内存泄漏（对象指针销毁，指向的对象也会被销毁）
    //而且可以完全控制内存分配方案，
    //但是堆栈中的每个对象都需要用new进行独立内存分配，相比于非线程安全版本，开销更大
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m) if (data.empty()) throw empty_stack(); // 在调用pop前，检查栈是否为空
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));             // 在修改堆栈前，分配出返回值

        data.pop();
        return res;
    }

    void pop(T &value)
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = data.top();
        data.pop();
    }
    //???????????????????????????
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

