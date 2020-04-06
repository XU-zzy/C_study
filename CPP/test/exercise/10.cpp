//条件状态
#include <iostream>

using namespace std;

void check(istream& is){
    cout << "检查cin的状态:" << endl;

    //系统级错误
    if(is.bad()){
        cout << "cin bad()" << endl;
    } else{
        cout << "cin is not bad()" << endl;
    }

    //输入的是数字，但是需要输入字符，数字无法转换成字符时，出现错误
    if(is.fail()){
        cout << "cin fail()" << endl;
    }else{
        cout << "cin is not fail()" << endl;
    }

    //文件结尾
    if(is.eof()){
        cout << "cin.eof()" << endl;
    }else{
        cout << "cin not eof" << endl;
    }

    if(is.good()){
        cout << "cin good" << endl;
    }
}

int main(){

    cout << "输入一个整数:" << endl;
    check(cin);

    int n;
    cin >> n;

    cout << "再检查cin" << endl;
    check(cin);
    return 0;
}
