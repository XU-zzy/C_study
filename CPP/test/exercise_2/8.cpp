//友元
//当一个类，或者类中的函数，想要使用，或者改变另一个类中私有的成员时，需要先成为另一个类的友元
#include<iostream>
#include<string>

using namespace std;

//注意这里只是将Dog类中的其中一个函数作为Screen的友元时，
//需要注意类和函数声明，以及类和函数定义的位置顺序
class Screen;
class Dog{
public:
    int foo(Screen &s);
};

class Screen{
public :
    //声明友元
    friend int calcArea(Screen& );
    friend class Window_Mgr;
    friend int Dog::foo(Screen &);


    typedef std:: string::size_type index;

    Screen(int ht = 0,int wd = 0):contents(ht*wd,' '),cursor(0),height(ht),width(wd){}

    int area() const{
        return height * width;
    }
    
private:
    std::string contents;
    index cursor;
    int height,width;
};

int calcArea(Screen& screen){
    return screen.height * screen.width;
}

//放在下面，放即使定义了Screen，也无法编译通过
class Window_Mgr{   //窗口管理
    public:
    void relocate(int r,int c,Screen& s){
            s.height += r;
            s.width += c;
    }
};

int Dog:: foo(Screen &s){
            return s.height * s.width;
}

int main(){

    Screen a(60,100);

    cout << a.area() << endl;

    cout << calcArea(a) << endl;

    Window_Mgr wm;
    wm.relocate(20,100,a);

    cout << calcArea(a) << endl;

    cout  << "okk" << endl;

    return 0;
}