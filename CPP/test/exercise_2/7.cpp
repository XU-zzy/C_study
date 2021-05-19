//构造函数
//创建对象时就是调用构造函数来对对象进行初始化
//如果永远不需要，也允许作为const
#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(const std::string &nm):name(nm),age(0){}
public:
    std::string name;
    int age;    //不可以在这里初始化
};

class Dog{
public:
    //由于要初始化的变量是 cosnt 类型，所以只能用初始化列表进行初始化
    //除此之外，需要这样操作的还有 引用类型 和 没有默认构造函数的类类型(就是有自己定义的有参数的构造函数的类)，
    //自己没有定义构造函数或者定义的构造函数中没有一个含参，那么系统就会自动定义一个不含参的默认构造函数
    Dog():leg(4){}  
private:
    const int leg;     
};

class Sales_item{
public:
    //构造函数可重载
    //最好是使用初始化列表对成员进行初始化
    //初始化列表的顺序并不是成员初始化的顺序，c++是按照定义成员的顺序进行初始化的
    //显式构造函数
    explicit Sales_item(const std::string &book = ""):isbn(book),units_sold(0),revenue(0.0){}    
    //const std::string &book = ""的写法可以省略下面这个函数,
    //当没有传入参数时，book自己初始化为空串，isbn，有参数时初始化为传入的参数
    //Sales_item():units_sold(0),revenue(0.0){}
    
    //以下两种初始化是不一样的
    Sales_item(unsigned units,double reve){     //比较慢，因为即使没有在函数体内进行初始化，但在这一行时，c++仍然会对对象成员进行初始化，等于这样是进行了两次初始化
        this->units_sold = units;
        this->revenue = reve;
    }
    
    //显式构造函数
    explicit Sales_item(std::istream &is){is >> *this;}
    //重载运算符
    friend std:: istream& operator >> (std::istream&,Sales_item&);

    bool same_isbn(const Sales_item &rhs ) const{     
        return this->isbn == rhs.isbn;
    }

private:
    std::string isbn;   //由于是一个类类型，所以即使我们并没有对其进行初始化，系统也会对它进行初始化为空串
    unsigned units_sold;
    double revenue;
};

inline istream& operator >> (istream& in,Sales_item& s){
    double price;
    in >> s.isbn >> s.units_sold >> price;
    if(in){
        s.revenue = s.units_sold * price;
    }else{
        s = Sales_item();
    }
    return in;
}

int main(){
    int k = 0;
    Person a("张飞");
    Sales_item item1;
    Sales_item item2("0-201-82470-1");

    // // 当构造函数只有一个参数时，有可能会出现下面的情况：
    // // 将仅有的一个参数构造为本身的对象类型
    // // 可以在此类构造函数前添加  explicit    来显式构造函数，避免此类情况发生
    // // 如果这样做，其中可以接受字符串的一个构造函数会直接用下面的字符串"9-999-9999-9"，创建一个临时的对象和item2进行比较
    // if(item2.same_isbn("9-999-9999-9")){

    // }

    // if(item2.same_isbn(cin)){

    // }

    Sales_item *p = new Sales_item();

    delete p;
}

// 默认构造函数（default constructor）就是在没有显式提供初始化式时调用的构造函数。
//它由不带参数的构造函数，或者为所有的形参提供默认实参的构造函数定义。
//如果定义某个类的变量时没有提供初始化式就会使用默认构造函数。
// 如果用户定义的类中没有显式的定义任何构造函数，编译器就会自动为该类型生成默认构造函数，称为合成的构造函数（synthesized default constructor）。
// 如果类包含内置或复合类型的成员，则该类就不应该依赖于合成的默认构造函数，它应该定义自己的构造函数来初始化这些成员。

// 多数情况下，编译器为类生成一个公有的默认构造函数，只有下面两种情况例外:
// 1.一个类显式地声明了任何构造函数，编译器不生成公有的默认构造函数。这这种情况下，如果程序需要一个默认构造函数，需要由类的设计者提供。
// 举例说明：比如说：下面的A就没有默认构造函数。
// class A
// {
// A(int);
// };
// 2.一个类声明了一个非公有的默认构造函数，编译器不会生成公有的默认构造函数。