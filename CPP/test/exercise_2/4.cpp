//this指针和mutable
#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(const std::string &nm,const std::string &addr){
        this->name = nm;
        this->address = addr;
    }
    std::string getName() const{
        return this->name;
    }
    std::string getaddress() const{
        return this->address;
    }
private:
    std::string name;
    std::string address;
};

class Screen{
public:
    typedef std::string::size_type index;

    Screen(index ht = 0,index wd = 0):contents(ht * wd,'A'),cursor(0),height(ht),width(wd){}
    Screen(index ht,index wd, const std::string &conts);

    char get() const;

    char get(std::string::size_type r,std::string::size_type c) const;

private:

    mutable a;      //计数器，在const成员函数里也可变

    std::string contents;
    index cursor;
    index height,width;

};

Screen::Screen(index ht,index wd, const std::string &conts):contents(conts),cursor(0),height(ht),width(wd){

}

inline char Screen::get() const {
    return contents[cursor];
}

char Screen::get(std::string::size_type r,std::string::size_type c) const{
    index row = r * width;
//        std::string::size_type
    return contents[row + c];
}

int main(){

    Person p("zzz","huayuan");
    Person p2("yyy","xxxx");
    cout << p.getName() << p2.getName() << endl;
    return 0;
}