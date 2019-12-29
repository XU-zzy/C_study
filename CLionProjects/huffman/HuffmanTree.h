//
// Created by zzy on 2019/12/29.
//
//哈夫曼树的创建

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

//虚定义
class HuffmanTree;

//有序表
class OrList{
public:
    OrList(int size = 0);
    ~OrList();
    HuffmanTree **OrListArray;

    //设置位置
    void Setstart();
    //返回表长
    int GetListLength();
    //取一个结点
    HuffmanTree *Getremove();
    //比较俩结点的权
    bool CompWeight(HuffmanTree *l,HuffmanTree *r);
private:
    int MaxSize;    //最大值
    int ListSize;   //表长
    int fence;      //位置
};


//哈夫曼树
class HuffmanTree {
public:
    HuffmanTree *root = new HuffmanTree;    //根结点

    HuffmanTree();
    //将左右结点连到同一个结点
    HuffmanTree(HuffmanTree *Lnode,HuffmanTree *Rnode);
    //创建结点
    HuffmanTree(unsigned  char value_t,unsigned int weight_t);
    //根据有序表建立哈夫曼树
    HuffmanTree *BuildHuffmanTree(OrList *List);

    unsigned int weight;    //权
private:
    unsigned char value;    //值
    unsigned int LorRChild;     //左孩子为0,右孩子为1
    HuffmanTree *LChild;    //左孩子
    HuffmanTree *RChild;    //右孩子
    HuffmanTree *Parent;    //父结点
    bool IsLeaf;            //判断是否为叶子结点
};


#endif //HUFFMAN_HUFFMANTREE_H
