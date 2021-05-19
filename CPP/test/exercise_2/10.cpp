//复制构造函数和赋值操作符
//如果没写的话，c++也会自动帮我们写一个
//但是当一个类中的数据成员有指针的时候，动态分配了内存的时候，就需要自己写
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Sales_item{
public:
    //普通构造函数
    Sales_item():units_sold(0),revenue(0){
        cout << "Sales_item():units_sold(0),revenue(0)默认构造函数被调用" <<endl;
    }
    Sales_item(const std::string &book)
        :isbn(book),
        units_sold(0),
        revenue(0){
            cout << "构造函数Sales_item(const std::string &book)被调用" << endl;
        }

    //复制构造函数
    Sales_item(const Sales_item &orig)
        :isbn(orig.isbn),
        units_sold(orig.units_sold),
        revenue(orig.revenue){
            cout << "复制构造函数已被调用" << endl;
        }

    //赋值操作符
    Sales_item& operator = (const Sales_item &rhs){
        cout << "赋值操作符被调用" << endl;
        isbn = rhs.isbn;
        units_sold = rhs.units_sold;
        revenue = rhs.revenue;
        return *this;
    }


private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

//函数按值传递，会调用复制构造函数
//按引用传递就不会了
//如果返回值是个引用，也不用复制了
Sales_item foo(Sales_item &item){
    Sales_item temp;
    temp = item;
    return temp;
}

//由于类中的成员有指针，就得自己写一个复制构造函数
//系统自己写的不能很好地处理指针，它会直接让新的指针指向原指针指向的位置
class NoName{
public:
    NoName():pstring(new std::string),i(0),d(0){}

    //复制构造函数
    NoName(const NoName& other):pstring(new std::string(*(other.pstring))),i(other.i),d(other.d) {
        cout << "NoName Copy Constructor" << endl;
    }

    //赋值操作符
    NoName& operator = (const NoName &rhs){
        pstring = new std::string;
        *pstring = *(rhs.pstring);

        i = rhs.i;
        d = rhs.d;
        cout << "NoName赋值操作符" <<endl;
        return *this;
    }

private:
    std::string *pstring;
    int i;
    double d;
};

int main(){
    NoName x,y;
    NoName z(x);
    x = y;

    Sales_item a;
    Sales_item b("0-201-78345-X");

    //调用复制构造函数
    Sales_item c(b);
    //赋值操作符被调用
    a = b;

    Sales_item item = string("9-999-99999-9");

    cout << endl << "foo函数"  << endl;
    Sales_item ret;
    // cout << "foo函数"  << endl;
    ret = foo(item);


    cout << endl << "试一下vector" << endl;
    vector<Sales_item> svec(5);

    cout << endl << "试一下数组：" << endl;
    Sales_item primer_eds[] = {
        string("0-201-16487-6"),
        string("0-201-16487-7"),
        string("0-201-16487-8"),
        Sales_item()
    };
    return 0;
}