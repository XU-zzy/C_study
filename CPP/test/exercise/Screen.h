#pragma once
#include<iostream>

class Screen
{
public:
    typedef std::string::size_type pos;
    
    Screen() = default;
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
    
    char get()const{     //读取光标处字符
        return contents[cursor];
    }  //隐式内联
    inline char get(pos ht,pos wd) const;   //
    Screen &move(pos r,pos c);      //能在之后被设为内联
    
    Screen &set(pos,pos,char);
    Screen &set(char);
    
    //根据对象是否为const重载display函数
    Screen &display(std::ostream &os){ 
        do_display(os);
        return *this; 
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0,width = 0;
    std::string contents;
    
    //显示Screen 的内容
    void do_display(std::ostream &os) const {os << contents;}
};

inline Screen &Screen::set (char c){
    contents[cursor] = c;       //设置光标所在位置的新值
    return *this;               //将this对象作为左值返回
}

inline Screen &Screen::set(pos r,pos col,char ch){
    contents[r*width + col] = ch;       //设置给定位置的新值
    return *this;                       //将this对象作为左值返回
}

inline Screen &Screen::move(pos r,pos c){
    pos row = r*width;      //行位置
    cursor = row + c;       //在行内将光标移动到指定的列
    return *this;
}

char Screen::get(pos r,pos c)const{     //在类内部声明成inline
    pos row = r*width;
    return contents[row+c];              //返回给定列的字符
}

