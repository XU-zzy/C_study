#include <iostream>

class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book) {  }
    Sales_data(const std::string &book,const unsigned num,const double sellp,const double salep);
    Sales_data(std::istream &is);
private:
    std::string bookNo;              //书记编号
    unsigned unit_sold = 0;     //销售量
    double sellingprice = 0.0;  //原价
    double saleprice = 0.0;     //实价
    double discount = 0.0;      //折扣
};

Sales_data ::Sales_data(const std::string &book,const unsigned num,const double sellp,const double salep){
    bookNo = book;
    unit_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if(sellingprice != 0){
        discount = saleprice/sellingprice;
    }
}

