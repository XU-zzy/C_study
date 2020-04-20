//定义
#include <iostream>
#include <string>

using namespace std;

//销售项目
class Sales_item{
public:
    //这里的string &book要定义为const，
    //但如果你把一个临时变量当作非const引用参数传进来，
    //由于临时变量的特殊性，程序员并不能操作临时变量，
    //而且临时变量随时可能被释放掉，所以，一般说来，修改一个临时变量是毫无意义的，
    // 据此，c++编译器加入了临时变量不能作为非const引用的这个语义限制。
    Sales_item(const std::string &book, unsigned units,double amount)
        :isbn(book),units_sold(units),revenue(amount){

    }

    double avg_price() const{
        if(units_sold){
            return revenue / units_sold;
        } else{
            return 0;
        };
    }

    bool same_isbn(const Sales_item &rhs) const{
        return isbn == rhs.isbn;
    }

    void add(const Sales_item &rhs){
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
    }
private:
    std::string isbn;   //书号
    unsigned units_sold;    //销售数量
    double revenue;  //总金额
};

class Person{
    //成员(数据和函数)
    //成员默认私有
public:
    Person(const std::string &nm, const std::string &addr):name(nm),address(addr){  //用初始化列表
//        name =nm;
//        address = addr;
    }
    std::string getName() const {
        return name;
    }
    std::string getAddress() const {
        return address;
    }
private:
    string address;
    string name;
};

int main(){
    Person a("Bill","花园");

//    a.getAddress();
//    a.getName();

    cout << a.getName() << "," << a.getAddress() << endl;

    Sales_item x("0-399-82477-1",2,20.00);
    Sales_item y("0-399-82477-1",6,48.00);
    if(x.same_isbn(y)){
        x.add(y);
    }

    cout << "两个销售单的平均价: " << x.avg_price() << endl;



    return 0;
}
