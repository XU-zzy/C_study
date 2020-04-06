//练习
#include <iostream>
#include <fstream>

using namespace std;

ifstream& open_file(ifstream& in,const string &file){
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}

int main(){
    string FileName;
    ifstream inFile;
    cout << "Enter filename:" << endl;
    cin >> FileName;

//    inFile.open(...);
    open_file(inFile,FileName.c_str());
    if(!open_file(inFile,FileName.c_str())){
        cout << "error: can not open file " << FileName.c_str() << endl;
    }

    return 0;
}
