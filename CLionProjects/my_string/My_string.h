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
    My_string(int str_len,char c);
    ~My_string();

private:
    int str_len;
    char *str;
};


#endif //HUFFMAN_MY_STRING_H
