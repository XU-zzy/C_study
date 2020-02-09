//
// Created by zzy on 2019/12/29.
//

#include "HuffmanCoding.h"
#include <fstream>


StackNode::StackNode(StackNode *nextval) {
    next = nextval;
}

StackNode::StackNode(unsigned int &num_t, StackNode *nextval) {
    std::cout << "Loading....14." << std::endl;
//    num = num_t;
    std::cout << "Loading....15." << std::endl;
    next = nextval;
    std::cout << "Loading....16." << std::endl;
}

LinkStack::LinkStack() {
    top = NULL;
    LinkStackSize = 0;
}

//删除栈
bool LinkStack::clear() {

    while(top){
        StackNode *temp = top;
        top = top->next;
        delete temp;
    }
    LinkStackSize = 0;
    return true;
}

//入栈
bool LinkStack::push(unsigned int &value_1) {
    std::cout << "Loading....111." << std::endl;

    top = new StackNode(value_1,top);

    ++LinkStackSize;
    return true;
}

//出栈
bool LinkStack::pop(unsigned int &value_2) {
    if(!LinkStackSize){
        return false;
    }
    value_2 = top->num;
    StackNode *temp = top;
    top = top->next;
    delete temp;
    --LinkStackSize;
    return true;
}

//清空缓冲区
void Buffer::ClearBuffer() {
    bit = 0;
    byte = 0;
}

//扫描文件，计算出现过的字符的权值
//建立有序表
//将有序表等信息写到目标文件头
void HuffmanCoding::BulidOrList() {
    //初始化权值数组
    for(int i = 0;i < 257;i++){
        ch[i] = 0;
    }
    //文件指针指向文件起始位置
    rewind(OrginalFile);
    unsigned char tempchar = fgetc(OrginalFile);
    //扫描文件，获得权值数组
    total = 0;
    while(!feof(OrginalFile)){
        ++ch[tempchar];
        ++total;
        tempchar = fgetc(OrginalFile);
    }

    //计算所需要建立的叶子结点的个数
    for(int i = 0;i < 257;i++){
        if(ch[i]){
            ++LeafNodeNum;
        }
    }

    //文件头写入字符总数和叶子结点总数
    fwrite(&total,sizeof(unsigned long int),1,TargetFile);
    fwrite(&LeafNodeNum, sizeof(unsigned int),1,TargetFile);

    //创建有序表并将其写入目标文件
    List = new OrList(LeafNodeNum);
    List_t = new OrList(LeafNodeNum);
    HuffmanTree *temp;

    for(int i = 0;i < 257;i++){
        if(ch[i] > 0){
            temp = new HuffmanTree(i,ch[i]);
            List->InsertNode(temp);
            save.ch = i;
            save.val = ch[i];
            fwrite(&save,sizeof(save),1,TargetFile);
        }
    }
}





//进行压缩
void HuffmanCoding::code() {
    total = 0;
    LeafNodeNum = 0;

    char* OrginFileName = new char[100];
    char* TargetFileName = new char[100];
    std::cout << "Please input the Source FIle's Name:" << std::endl;
    std::cin >> OrginFileName;

    OrginalFile = fopen(OrginFileName,"rb");
    while(!OrginalFile/* || feof((OrginalFile))*/){
        std::cout << "Can't find the file or the file is empty!" << OrginFileName << std::endl;
        std::cout << "Please input the Source FIle's Name again:" << std::endl;
        std::cin >> OrginFileName;
        OrginalFile = fopen(OrginFileName,"rb");
    }

    std::cout << "Please input the Compressed File's Name:" << std::endl;
    std::cin >> TargetFileName;

    while(!(TargetFile = fopen(TargetFileName,"wb"))){
        std::cout << "Creat File " << TargetFileName << "failed!" << std::endl;
        std::cout << "Please input the Compressed File's Name again:" << std::endl;
        std::cin >> TargetFileName;
    }

    std::cout << "Loading....." << std::endl;

    //建立有序表，并将相关信息写入文件头
    BulidOrList();

    //建立哈夫曼树
    HuffmanTree *tree;

    Tree = Tree->BuildHuffmanTree(List,List_t);



    //编码
    rewind(OrginalFile);
    unsigned int tempint;
    HuffmanTree* temptreenode;
    Stack = new LinkStack();
    buffer.ClearBuffer();
    unsigned char tempchar = fgetc(OrginalFile);
    while(!feof(OrginalFile)){

        //搜索匹配
        for(int i = 0;i < List_t->GetListLength();i++){
            if(tempchar == List_t->OrListArray[i]->value){
                Stack->clear();
                temptreenode = List_t->OrListArray[i];
                //编写
                while(temptreenode != Tree){
                    std::cout << "Loading....13." << std::endl;
                    Stack->push(temptreenode->LorRChild);
                    std::cout << "Loading....1." << std::endl;
                    std::cout << "Loading....2." << std::endl;
                    temptreenode = temptreenode->Parent;
                    std::cout << "Loading....12." << std::endl;
                }
                std::cout << "Loading....10." << std::endl;

                while(Stack->pop(tempint)){
                    code_write(tempint);
                }
                break;
            }
        }
        tempchar = getc(OrginalFile);
    }


    //最后缓存中存在不足8位的数据
    if(buffer.bit){
        for(unsigned int i = buffer.bit;i < 8;i++){
            code_write(0);
        }
    }
    std::cout << "Successed!" << std::endl;

    //计算压缩比
    fseek(OrginalFile,0L,SEEK_END);
    double size_OrginalFile = ftell(OrginalFile);
    fseek(TargetFile,0L,SEEK_END);
    double size_TargetFile = ftell(TargetFile);

    std::cout << "Compression ratio(Source/compressed files):" << (size_OrginalFile/size_TargetFile) << std::endl;

//    delete Stack;
//    delete List;
    fclose(OrginalFile);
    fclose(TargetFile);
}

//通过buffer向目标文件一位一位地写入
void HuffmanCoding::code_write(unsigned int ch) {
    ++buffer.bit;
    buffer.byte = (buffer.byte << 1) + ch;
    if(buffer.bit == 8){
        fputc(buffer.byte,TargetFile);
        buffer.ClearBuffer();
    }
}
