//文件模式
#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string s;


//    ifstream ifs ("one.txt",ifstream::in);
    ifstream ifs("one.txt");
    ifs >> s;
    cout << s << endl;
    ifs.close();

    //下面三个相同
//    ofstream ofs("file2.txt",ostream::out);
//    ofstream ofs("file2.txt");      //默认为out,会清空源文件
//    ofstream ofs("file2.txt", | ofstream::trunc);
    //文件内容追加
    ofstream ofs("file2.txt",ofstream::out | ofstream::app);
    ofs.close();
    ofs << "hello file2";

//    fstream fs("file2.txt");
    fstream fs("file2.txt",fstream::in | fstream::out); //不会清空文件
//    fstream fs("file2.txt",fstream::in | fstream::out | fstream::trunc); //会清空文件

    fs >> s;
    fs.close();
    cout << s;

    fs.close();

    return 0;
}

