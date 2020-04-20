#include <iostream>
#include <string>

using namespace std;

class Screen;   //类声明,只有声明可以定义指针和引用，但是不能定义类

//记录
//这是一个完整的类;类定义，类声明
class Record{
public:
    typedef std::size_t size;
    Record():byte_cout(0){};
    Record(size s):byte_cout(s){}
    Record(std::string s):name(s),byte_cout(0){}
private:
    std::string name;   //记录名称
    size byte_cout;
};

int main(){
    Record r;

    cout << "hello" << endl;

    return 0;
}