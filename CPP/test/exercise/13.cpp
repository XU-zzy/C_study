//文件流对象使用
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void process(string s){
    cout << s << endl;
}

int main(){
    vector<string> files;

    files.push_back("one.txt");
    files.push_back("two.txt");
    files.push_back("three.txt");

    vector<string>::const_iterator it = files.begin();

    while (it != files.end()){
        ifstream input(it->c_str());
        if(!input){
            cerr << "error: can not open file:" << *it << endl;
            input.clear();
            ++it;
            continue;
        }
        string s;
        while(input >> s){
            process(s);
        }
        input.close();
        input.clear();
        it++;
    }

}
