//
// Created by zzy on 2019/12/29.
//

#ifndef HUFFMAN_HUFFMANCODING_H
#define HUFFMAN_HUFFMANCODING_H

#include <iostream>
#include <netdb.h>
#include "HuffmanTree.h"

//栈结点
struct StackNode{
public:

    StackNode(const unsigned int &num_t, StackNode *nextval = NULL);

    StackNode(StackNode *nextval = NULL);

    StackNode *next;
    unsigned int num;
};

//链栈
struct LinkStack{
    StackNode *top;
    int LinkStackSize;

    LinkStack();
    ~LinkStack(){
        clear();
    };
    bool clear();

    bool push(const unsigned int &value_1);
    bool pop(unsigned int &value_2);
};

class Buffer{
public:
    char byte;   //字节
    char bit;    //位
    void ClearBuffer();
};

class Save{
public:
    unsigned char ch;
    unsigned int val;
};

class HuffmanCoding {
private:
    OrList *List,*List_t;       //有序表
    HuffmanTree *Tree;  //哈夫曼树
    Buffer  buffer;     //缓冲区
    Save save;          //临时存储叶子区
    FILE *OrginalFile;  //原文件
    FILE *TargetFile;   //目标文件
    unsigned LeafNodeNum;       //所需要建立的叶子结点的个数
    unsigned long int total;    //要进行编码的文件总字节数
    unsigned long int ch[258];  //原文件内ASCII码对应数组下标的值是起权值
public:
    void BulidOrList();     //建立有序表
    void read_OrList();     //导出有序表
    void code();            //压缩
    void decode();          //解压缩
    void code_write(unsigned int ch);           //通过位操作向文件中写入编码
    unsigned int decode_read();            //读出编码
    LinkStack *Stack;   //栈
};


#endif //HUFFMAN_HUFFMANCODING_H
