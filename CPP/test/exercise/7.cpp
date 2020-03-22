//重载与作用域
#include <iostream>
#include <string>

using namespace std;

string init(){
    return "hello";
}

void fcn(){
    int init = 0;       //该变量名init和上面函数名init()相同，则从此后，屏蔽了函数init()
    string s = init();
    cout << s << endl;
}

int main(){
    fcn();
    return 0;
}

