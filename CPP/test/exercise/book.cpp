#include <iostream>
#include"book.h"

int main()
{
    std::cout << "Hello world" << std::endl;
    book B(cin);
    
    B.display(cout);

    return 0;
}

