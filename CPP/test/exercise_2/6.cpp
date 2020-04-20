//构造函数
#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(const std::string &nm):name(nm),age(0){}

public:
    std::string name;
    int age;
};

class Sales_item{
public:
    Sales_item(const std::string &book):isbn(book),units_sold(0),revenue(0.0){}

    Sales_item():units_sold(0),revenue(0.0){}


    friend std::istream& operator>>(std::istream&,Sales_item);
private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

inline istream operator >>(istream& in,Sales_item& s){
    double price;
    in >> s.isbn
}

int main(){
    int k = 0;
    Person a("张飞");
    Sales_item item1;
    Sales_item item2("0-201-82470-1");
}