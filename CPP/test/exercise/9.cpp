#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//流对象传参必须传引用或指针
//同时，不能做返回值，因为返回值也是需要复制的
//void print(ofstream of){
//    cout << "test" << endl;
//}
void print(ofstream &of){
    cout << "test" << endl;
}

void foo(ostream &os){
    cout << "test" << endl;
}

int main(){

    foo(cout);

    //可接收基类的位置，都可以接收子类，多态
    ofstream ofs;
    foo(ofs);

    //cout是ostream的输出流对象
    std::cout << "hello" << std::endl;

    std::fstream fs;
    std::stringstream ss;
    //I/O对象不可赋值和复制

    ofstream out1,out2;

//    out1 = out2;    //错误
    print(out1);

    //错误，向量
//    vector<ofstream> vec;
//    vec.push_back(out1);
//    vec.push_back(out2);

    return 0;
}