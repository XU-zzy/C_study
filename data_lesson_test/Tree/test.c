#include <stdio.h>
#include <stdlib.h>
#define TElemType char

typedef struct BiTNode{
    TElemType data;     //结点数据
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
/*
//创建二叉树
void CreatBiTree(BiTree *T){
    TElemType ch;
    scanf("%c",&ch);
    getchar();
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        
        if(!*T){
            exit(1);
        }
        
        (*T)->data = ch;    //生成结点
        CreatBiTree(&(*T)->lchild); //左子树
        (*T)->data = ch;
        printf("%c\n",(*T)->data);
        CreatBiTree(&(*T)->rchild); //右子树
        (*T)->data = ch;
    }
}*/

void CreatBiTree(BiTree *T){
    TElemType ch;
    scanf("%c",&ch);
    getchar();
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        
        if(!*T){
            exit(1);
        }
        
        /* (*T)->data = ch;    //生成结点 */
        CreatBiTree(&(*T)->lchild); //左子树
        (*T)->data = ch;                                                                                                                                 
        printf("%c\n",(*T)->data);
        CreatBiTree(&(*T)->rchild); //右子树
        /* (*T)->data = ch; */
    } 
} 


//前序遍历二叉树
void PreOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }

    printf("%c ",T->data);  //显示结点数据
    PreOrderTraverse(T->lchild);    //遍历左子树
    /* printf("%c ",T->data);  //显示结点数据 */
    PreOrderTraverse(T->rchild);    //遍历右子树
    /* printf("%c ",T->data);  //显示结点数据 */
}

int main()
{
    BiTree T;
    CreatBiTree(&T);
    PreOrderTraverse(T);
    printf("\n");
    return 0;
}

