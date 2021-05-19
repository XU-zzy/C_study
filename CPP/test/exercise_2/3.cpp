#include <iostream>
#include <string>

using namespace std;

class Screen;   //类声明,只有声明可以定义指针和引用，但是不能定义类

//在开头第一行已经声明过Link_Screen，所以在类中可以直接定义其指针成员或者引用，但是不能定义对象
class Link_Screen{
    Screen *window;
    Link_Screen *next;
    Link_Screen *prev;
};

class Y;    //声明

class X{
    //成员略

    private:
    Y *ptr;     //这里只有声明以后才能定义这样的指针
};

class    Y{  //定义
    //成员略

    private:
    X *ptr;
    X obj;
};
//这样需要在X中有成员是Y，Y中有成员是X，这样就需要先给其中一个先前置声明



//记录
//这是一个完整的类;类定义，类声明
class Record{
public:
    typedef std::size_t size;
    Record():byte_cout(0){};
    Record(size s):byte_cout(s){}
    Record(std::string s):name(s),byte_cout(0){}

    size get_count() const {return byte_cout;}
    std::string get_name() const {return name;}

private:
    std::string name;   //记录名称
    size byte_cout; //字节数量
};

int main(){
    Record r;//定义后，c++才能开始分配内存      //在堆栈上创建对象

    Record *p = new Record;     //在堆上动态地创建对象

    delete p;
    cout << "hello" << endl;

    return 0;
}