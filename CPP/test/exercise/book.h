#pragma once
#include<iostream>
using namespace std;


class book{
public:
    book() = default;
    book(string n,string i,string a,string p,double pr){
        Name = n;
        ISBN = i;
        Author = a;
        Publisher = p;
        Price = pr;
    } 
    book(istream &is){
        is >> this->Name >> this->ISBN >> this->Author >> this->Publisher >> this->Price;
    }
    book& display(ostream &os){
        os << this->Name << " " << this->ISBN << " " << this->Author << " " << this->Publisher << " " << this->Price << endl;
        return *this;
    }
private:
    string Name,ISBN,Author,Publisher;
    double Price = 0;
};

