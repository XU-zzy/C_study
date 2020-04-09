#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string fileName,s;
    vector<string> svec;
    string word;

    istringstream isstream;

    fileName = "hello.txt";

    ifstream inFile(fileName.c_str());

    if(!inFile) return -1;

    while(getline(inFile,s)){
        svec.push_back(s);
    }

    inFile.close();

    for(vector<string>::const_iterator iter = svec.begin();
        iter != svec.end();iter++){
//        cout << *iter << endl;
        isstream.str(*iter);
        while(isstream >> word){        //拆分成单词
            cout << word << endl;
        }
        isstream.clear();
    }

    return 0;
}

