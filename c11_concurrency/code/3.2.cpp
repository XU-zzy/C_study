//用锁保护过的数据由于设计问题，使得保护失败
#include <list>
#include <mutex>
#include <algorithm>
#include <string>

class some_data
{
    int a;
    std::string b;

public:
    void do_something();
};
class data_wrapper
{
private:
    some_data data;
    std::mutex m;

public:
    template <typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data); // 1 传递“保护”数据给用户函数
    }
};
some_data *unprotected;
void malicious_function(some_data &protected_data)
{
    unprotected = &protected_data;
}
data_wrapper x;
void foo()
{
    x.process_data(malicious_function); // 2 传递一个恶意函数
    unprotected->do_something();        // 3 在无保护的情况下访问保护数据
}