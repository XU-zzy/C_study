//深复制和浅复制
//类里面有指针需要写深复制，
//当类动态地分配了系统资源时，也需要写，动态分配
#include<iostream>
#include<cstring>

using namespace std;

class CDemo
{
private:
    /* data */
public:
    //成员应该私有
    int a;
    char *str;

    //没有写复制构造函数，系统会自己写
    //但是系统写的只是浅复制，会将两个对象里的指针成员指向同一个值
    //深复制，是重新申请一个空间，然后将值复制到新的空间中

    CDemo(int pa, char * cstr) {
        this->a = pa;
        this->str = new char[1024];
        strcpy(this->str,cstr);
    }

    //深复制
    CDemo(const CDemo& other) {
        this->a = other.a;
        this->str = new char[1024];
        if(str != 0){
            strcpy(this->str,other.str);
        }
    }

    ~CDemo() {
        delete str;
    }
};

int main(){

    CDemo A(10,"hello");
    CDemo B = A;//复制

    cout << A.a << ", " << A.str << endl;
    cout << B.a << ", " << B.str << endl;

    B.a = 8;
    B.str[0] = 'K'; //由于是浅复制，所以也改变了A
    cout << A.a << ", " << A.str << endl;
    cout << B.a << ", " << B.str << endl;

    return 0;
}