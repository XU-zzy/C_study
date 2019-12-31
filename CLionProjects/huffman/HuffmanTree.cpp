//
// Created by zzy on 2019/12/29.
//
#include <iostream>
#include "HuffmanTree.h"

//构造函数
OrList::OrList(int size) {
    MaxSize = size;
    fence = 0;
    ListSize = 0;
    OrListArray = new HuffmanTree*[MaxSize];
}

OrList::~OrList() {
    delete[]OrListArray;
}

//设置位置
void OrList::Setstart() {
    fence = 0;
}

//返回表长
int OrList::GetListLength() {
    return ListSize;
}

//比较俩结点的权
bool OrList::CompWeight(HuffmanTree *l, HuffmanTree *r) {
    return l->weight > r->weight;
}

//插入表结点
bool OrList::InsertNode(HuffmanTree *node) {
    if(ListSize == MaxSize){
        return false;
    }
    HuffmanTree *temp;
    //寻找插入位置
    for(fence = 0;fence < ListSize;fence++){
        temp = OrListArray[fence];
        if(CompWeight(temp,node)){
            break;
        }
    }
    for(int i = ListSize;i > fence;i--){
        OrListArray[i] = OrListArray[i-1];
    }
    OrListArray[fence] = node;
    ++ListSize;
//    std::cout << ListSize << std::endl;
    return true;
}

//获得一个结点并前移
HuffmanTree* OrList::Getremove() {
    //如果是表尾，则返回
    if(ListSize == fence){
        return NULL;
    }

    HuffmanTree *temp = OrListArray[fence];
    for(int i = fence;i < ListSize - 1;i++){
        OrListArray[i] = OrListArray[i+1];
    }

    --ListSize;
    return temp;
}

//创建哈夫曼结点
HuffmanTree::HuffmanTree() {
//    HuffmanTree *root = new HuffmanTree;    //根结点
    weight = 0;
    IsLeaf = true;
}

HuffmanTree::HuffmanTree(HuffmanTree *Lnode, HuffmanTree *Rnode) {
    LChild = Lnode;
    RChild = Rnode;
    weight = Lnode->weight + Rnode->weight;
    IsLeaf = false;
    Lnode->Parent = Rnode->Parent = root;
}

HuffmanTree::HuffmanTree(unsigned char value_t, unsigned int weight_t) {
    value = value_t;
//    std::cout << value << std::endl;
    weight = weight_t;
    IsLeaf = true;
}

//创建哈夫曼树
HuffmanTree* HuffmanTree::BuildHuffmanTree(OrList *List,OrList *List_t) {
    HuffmanTree *tr_1 = new HuffmanTree();
    HuffmanTree *tr_2 = new HuffmanTree();
    HuffmanTree *tr_3 = new HuffmanTree();
    for(int i = List->GetListLength();i > 1;i--){
        //设置表位置到开始
        List->Setstart();
        //取结点
        tr_1 = List->Getremove();
        tr_1->LorRChild = 0;
        tr_2 = List->Getremove();
        tr_2->LorRChild = 1;
//        std::cout << "abc" << std::endl;

        tr_3 = new HuffmanTree(tr_1,tr_2);
//        if(List->InsertNode(tr_3)){
//            return NULL;
//        }

        if(tr_1->IsLeaf){
            List_t->InsertNode(tr_1);
        }
        if(tr_2->IsLeaf){
            List_t->InsertNode(tr_2);
        }

        List->InsertNode(tr_3);
    }

    return tr_3;
}