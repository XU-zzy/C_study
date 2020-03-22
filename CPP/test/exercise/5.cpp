//类的函数
#include <iostream>

using namespace std;

int sum(int x,int y){
    return x + y;
}

//销售 项目
class Sales_item{
public:

    double avg_price() const;   //函数声明

    //常成员函数，该函数不能对数据进行修改
    bool same_isbn(const Sales_item &rhs) const{
//        this->isbn = 99;
        return this->isbn == rhs.isbn;
    }

public:
    Sales_item():units_sold(0),revenue(0){}

//private:
public:
    std::string isbn;   //书号
    unsigned units_sold;    //数量
    double revenue;
};

double Sales_item::avg_price() const {
    if(this->units_sold){
        return (this->revenue / this->units_sold);
    }else{
        return 0;
    }
}

int main(){
    Sales_item item_1,item_2;

    item_1.isbn = "0-201-78345-X";
    item_1.units_sold = 10;
    item_1.revenue = 300.00;

    cout << "第一单的平均价格:" << item_1.avg_price() << endl;

    item_2.isbn = "0-201-78345-X";
    item_2.units_sold = 2;
    item_2.revenue = 70;

    cout << "第二单的平均价格:" << item_2.avg_price() << endl;

    if(item_1.same_isbn(item_2)){
        cout << "是同一种书" << endl;
    }else{
        cout << "不是同一种书" << endl;
    }

    return 0;
}