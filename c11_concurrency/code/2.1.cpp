#include <thread>

void do_something(int &i)
{
}

struct func
{
    int &i;
    func(int &i_) : i(i_) {}
    void operator()()
    {
        for (unsigned j = 0; j < 1000000; ++j)
        {
            do_something(i); // 1. 潜在访问隐患：悬空引用
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach(); // 2. 不等待线程结束
}

//等待线程完成
struct func; // 定义在清单2.1中
void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch (...)
    {
        t.join(); // 1
        throw;
    }
    t.join(); // 2
}

//使用RAII等待线程完成
class thread_guard
{
    std::thread &t;

public:
    explicit thread_guard(std::thread &t_) : t(t_)
    {
    }

    ~thread_guard()
    {
        //这里提前判断很重要，因为join只能对给定对象调用一次
        if (t.joinable()) // 1
        {
            t.join(); // 2
        }
    }

    //直接赋值或复制很危险
    //通过删除声明，使得每一个给thread_guard进行赋值的操作都会造成编译错误
    thread_guard(thread_guard const &) = delete; // 3
    thread_guard &operator=(thread_guard const &) = delete;
};
struct func; // 定义在清单2.1中

void do_something_in_current_thread()
{
}

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    do_something_in_current_thread();
} // 4
