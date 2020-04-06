//流的条件状态
#include <iostream>
#include <fstream>
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

    int sum = 0,value;
//    简单方法
//    while(cin >> value){  //一次性检查三个状态
//        sum += value;
//        cout << "Sum is "  << sum << endl;
//    }

    //设置状态 badbit所设置的装啊提取决于其中1的个数 00010000 bad  00011000 fail 00011100 eof
//    cin.setstate(istream::badbit);
    cin.setstate(istream::badbit | istream::failbit);

    cin.clear(istream::badbit);

    check(cin);

    //将一个流的状态保存下来
    istream::iostate old_state = cin.rdstate();
    //之后可随意使用流，
    //用完后，可以还原它的状态
    cin.clear(old_state);


    while(cin >> value, !cin.eof()){
        if(cin.bad()){
            throw std::runtime_error("IO stream corrupted");
        }

        if(cin.fail()){
            cerr << "bad data,try again" << endl;
            cin.clear();    //清空标志(bad,fail)，恢复正常流状态
            cin.ignore(200,'\n');   //清除流，要么清除200个，要么清除到'\n'
            continue;
        }

        sum += value;
        cout << "Sum is " << sum << endl;
    }

    return 0;
}