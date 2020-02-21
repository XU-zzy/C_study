//
// Created by zzy on 2020/2/16.
//

#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

class My_string {
public:
    My_string(int str_len);
    My_string(const char *str);
    ~My_string();

    My_string::My_string(const char *str) {
        if(*str == NULL){
            this->str_len = 0;
            this->str = new char[this->str_len + 1];
        }
    }

private:
    int str_len;
    char *str;

};


#endif //HUFFMAN_MY_STRING_H
