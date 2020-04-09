//字符串流
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    //cout 是流对象,ostream
    cout << "Hello!" << endl;

    //文件输出流
    ofstream ofs("hello.txt");

    ofs << "hhhhh" << endl;
    ofs.close();

    //字符串输出流
    ostringstream oss;
    oss << "hhh" << endl;

    cout << "显示字符串流的字符串 " << oss.str() << endl;


    ostringstream format_message;
    format_message << "姓名: " << "Jame " << "\n"
                    << "年龄: " << 35 << "体重: " << 208.3 << endl;

    cout << "显示Jame: \n" << format_message.str() << endl;

    string dump;
    string name;
    int age;
    double dun;

//    输入流会自动将字符串变成数字
    istringstream input_istring(format_message.str());
    input_istring >> dump;  //扔掉"姓名:"
    input_istring >> name;
    input_istring >> dump;
    input_istring >> age;
    input_istring >> dump;
    input_istring >> dun;

    cout << "结果: " << endl;
    cout << name << age << dun << endl;

    return 0;
}
