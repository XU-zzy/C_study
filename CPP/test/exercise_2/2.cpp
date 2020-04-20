//重载
#include <iostream>
#include <string>

using namespace std;

class Screen{
public:
    typedef std::string::size_type index;

    Screen(index ht = 0,index wd = 0):contents(ht * wd,'A'),cursor(0),height(ht),width(wd){}
    Screen(index ht,index wd, const std::string &conts);

    char get() const;

    char get(std::string::size_type r,std::string::size_type c) const;

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
    Screen a(10,100);

    cout << a.get() << endl;
    cout << a.get(2,8) << endl;

    Screen b(3,6,"hello screen class");

    cout << b.get() << endl;
    cout << b.get(1,2) << endl;

    cout << "success!" << endl;
}