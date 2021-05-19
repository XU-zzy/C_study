//static类成员
#include<iostream>
#include<string>

using namespace std;

//全局变量
// double interestRate;

class Account{
public:
    Account(std::string name,double maney):owner(name),amount(maney){}

    double getAmount(){
        return this->amount;
    }

    //存钱
    void deposit(double money){
        this->amount += money;
    }

    //静态的成员函数，不能使用类指针,this
    //因为它不属于任何一个对象，它属于类
    static double rate() {return interestRate;}
    static void rate(double newRate){
        interestRate = newRate;
    }

private:
    std::string owner;
    double amount;
    static double interestRate; //只有一个

    static const int period = 1;        //只有静态常量整型可以这样写！！！！
};

double Account::interestRate = 0.015;

//由于静态变量和函数都可以公用，所以叫做静态的类成员，是属于类的，而不是对象的组成部分
//是独立的 

int main(){

    // interestRate = 0.015;
    //由于函数是静态的，所以在没有创建函数之前，就可以这样做、
    Account::rate(0.013);

    Account a("张三",1000);
    Account b("李四",2000);
    a.deposit(500);
    b.deposit(600);

    cout << a.getAmount() << endl;
    cout << b.getAmount() << endl;
    cout << a.rate() << endl;
    b.rate(0.014);
    cout << b.rate() << endl;

    return 0;
}