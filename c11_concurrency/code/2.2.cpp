//std::thread实例传参用法
#include<thread>

void do_something_in_current_thread(){}
void do_something(int& i){}
struct func
{
	int& i;
	func(int& i_) : i(i_) {}
	void operator() ()
	{
		for (unsigned j=0 ; j<1000000 ; ++j)
		{
			do_something(i); // 1. 潜在访问隐患：悬空引用
		}
	}
};

class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_): // 1
    t(std::move(t_))
    {
        if(!t.joinable()) // 2
            throw std::logic_error("No thread");
    }
    ~scoped_thread()
    {
        t.join(); // 3
    }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void f()
{
    int some_local_state;
    scoped_thread t(std::thread(func(some_local_state))); // 4
    do_something_in_current_thread();
}