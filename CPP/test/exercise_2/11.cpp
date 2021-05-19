//析构函数
//在main函数结束的时候调用
//在构造函数中打开文件,连接数据库，动态分配内存，在析构函数中关闭，回收动态分配内存
//三法则
//析构函数写了以后，就一定要写复制构造函数和赋值操作符
#include<iostream>
using namespace std;

//这个就不需要自己写那三个
class Sales_item
{
private:
    std::string isbn;
    int units_sold;
    double revenue;
public:
    Sales_item() {}
    ~Sales_item() {}
};

class NoName
{
private:
    std::string *pstring;
    int i;
    double d;
public:
    NoName():pstring(new std::string),i(0),d(0) {
        cout << "构造函数" << endl;
    }
    ~NoName() ;

    //复制构造函数
    NoName(const NoName &other)
                :pstring(new std::string(*other.pstring)),
                i(other.i),
                d(other.d) {
                    cout << "复制构造函数" << endl;
                }
    //赋值操作符
    NoName &operator = (const NoName &rhs){
        pstring = new std::string;
        *pstring = *(rhs.pstring);
        this->d = rhs.d;
        this->i = rhs.i;
        
        cout << "赋值操作符" << endl;

        return *this;
    }
};

NoName::~NoName(){
    cout << "析构函数被调用了！" <<endl;
    delete pstring;
}

int main(){

    NoName a;
    //用new创建的对象就必须用delete，此时也会调用析构函数
    NoName *p = new NoName;

    NoName b(a),c;
    c = a;

    cout << "hello!" << endl;

    delete p;
    return 0;
}