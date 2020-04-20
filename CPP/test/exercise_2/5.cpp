//::作用域操作符
#include <iostream>

using namespace std;

void doA(){
    int a;
    a = 12;
}

void doB(){
    int b;
    b = 99;
}

class First{
public:
    int memi;
    double memd;
public:
    void doC(){
        memi = 22;
    }
    void doD(){
        doC();
    }
};



int main(){

    First obj;
    First *ptr = &obj;
    obj.memi = 12;
    obj.doC();
    return 0;
}