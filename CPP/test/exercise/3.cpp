//传参时，尽量直接传递迭代器
#include <vector>
#include <iostream>

using namespace std;

//非引用形参
void print(vector<double> v){
    vector<double>::iterator begin = v.begin();
    while(begin != v.end()){
        cout << *begin << endl;
        begin++;
    }
}

//引用形参
void print_2(vector<double>& v){
    vector<double>::iterator begin = v.begin();
    while(begin != v.end()){
        cout << *begin++ << endl;
    }
}

//传递迭代器最常见
void print_3(vector<double>::const_iterator beg,
        vector<double>::const_iterator end){
    while(beg != end){
        cout << *beg++;
        if(beg != end) cout << " ";
    }
    cout << endl;
}

double vectorSum(vector<double>::const_iterator beg,
        vector<double>::const_iterator end){
    double sum = 0;
    while (beg != end){
        sum += *beg++;
    }
    return sum;
}

int main(){
    vector<double> dvec;
    dvec.push_back(1.1);
    dvec.push_back(2.2);
    dvec.push_back(3.3);

    //把dvec复制到形参v
    //若v很大，会占用更多时间传参
//    print(dvec);
//    print_2(dvec);
//    print_3(dvec.begin(),dvec.end());
    cout << vectorSum(dvec.begin(),dvec.end()) << endl;
}