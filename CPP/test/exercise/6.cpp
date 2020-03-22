#include <iostream>

using namespace std;

class Person{
public:
    //默认构造函数
    Person():qian(0){
        //可以空着
    }

public:
//    static int 钱 = 0; //静态的才可以在类里面这样定义
    int qian;
};

int main(){
    //创建两个对象，需要调用构造函数
    Person a;
    Person my;

    cout << a.qian << endl;
    cout << my.qian << endl;
}