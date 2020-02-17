//
// Created by zzy on 2020/2/16.
//

#include "My_string.h"

My_string::My_string(int str_len) {
    if(str_len < 0){
        std::cout << "Wrong! str_len < 0!" << endl;
        return -1;
    }
    this->str_len = str_len;
    this->str = new char[this->str_len + 1];
    memset(this->str,0,this->str_len + 1);
}

My_string::My_string(const char *str) {
    if(*str == NULL){
        this->str_len = 0;
        this->str = new char[this->str_len + 1];
    }
}