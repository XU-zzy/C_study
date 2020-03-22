//指向函数的指针
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef bool (*cmpFun)(const string &,const string &);

bool lengthCompare(const string &s1,const string &s2){
    return s1.size() == s2.size();
}

void ff(vector<double> vec){
    cout <<  "ff(vector<double> vec)" << endl;
}

void ff(unsigned int x){
    cout << "ff(unsigned int x)" << endl;
}

int main(){
    bool (*pf)(const string &, const string &);

    pf = lengthCompare;

    cmpFun pf2 = lengthCompare;


    cout << lengthCompare("hello","pointer") << endl;
    cout << pf("hello","pointer") << endl;
    cout << pf2("hello","pointer") << endl;

    //指向重载函数，注意：这里必须精确匹配
    void (*pf5)(vector<double>) = &ff;
    void (*pf7)(unsigned int) = &ff;
    return 0;
}