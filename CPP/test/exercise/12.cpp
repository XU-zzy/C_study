//文件流对象的使用
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream outfile("test.txt");
    outfile << "hello file!";
    outfile.close();

    string file("one.txt");
//    ifstream infile(file.c_str());    //这里要用c_str,流与对象绑定

    //先不绑定需要用流打开一个文件
    ifstream infile;
    infile.open(file.c_str());

    if(!infile){
        cerr << "打开文件失败" << endl;
        return -1;
    }

    string s;
    while(infile >> s){
        cout << s << endl;
    }


    infile.close();     //关闭流，但状态依旧是eof
    infile.clear();     //恢复流
    //--------------------------------------
    file = "two.txt";
    infile.open(file.c_str());
    if(!infile){
        cerr << "打开文件失败" << file << endl;
        return -1;
    }
//    infile.open(file.c_str());

    if(!infile){
        cerr << "读取文件失败" << file << endl;
        return -1;
    }
    while(infile >> s){
        cout << s << endl;
    }
//    cout << "读到内容：" << s << endl;

    return 0;
}

