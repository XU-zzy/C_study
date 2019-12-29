#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//递归查找
bool SearchBST_digui(BiTree T,int key,BiTree f,BiTree *p){
    if(!T){     //查找不成功
        *p = f;
        return FALSE;
    }else if(key == T->data){   //查找成功
        *p = T;
        return TRUE;
    }else if(key < T->data){    //小于，查找左孩子
        return SearchBST_digui(T->lchild,key,T,p);
    }else{                      //大禹，查找右孩子
        return SearchBST_digui(T->rchild,key,T,p);
    }
}

//非递归查找
bool SearchBST_feidigui(BiTree T,int key){
    if(!*T){
        return FALSE;
    }
    
    while(T){
        if(T->data == key){
            return TRUE;
        }else if(T->data > key){
            T = T->lchild;
        }else{
            T = T->rchild;
        }
    }
    return FALSE;
}

//插入
bool InsertBST(BiTree *T,int key){
    BiTree p,s;
    if(!SearchBST_digui(*T,key,NULL,&p)){    //查找不成功
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p){
            *T = s;         //插入s为新的根结点
        }else if(key < p->data){
            p->lchild = s;  //插入s为左孩子
        }else{
            p->rchild = s;  //插入s为右孩子
        }
        return TRUE;
    }
    else{
        return FALSE;   //书中已有关键字相同结点，不再插入
    }
}

//删除树



int main(){
    int a[MAXSIZE] = {0};
    BiTree T = NULL;
    int n;
    
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        InsertBST(&T,a[i]);
    }
    
    
    return 0;
}
