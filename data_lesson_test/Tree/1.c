#include<stdio.h>
#include<stdlib.h>
  
 
typedef struct Binode{
    char data;
    struct Binode *lchild;
    struct Binode *rchild;
}Bitnode,*BiTree;
  
typedef struct stack{
    struct Binode ch;                                                 
    struct stack *next;
}Node;
 
typedef Node *Stack;
 
//结点总数目
int Count = 0;
int Count_1 = 0;
int Count_2 = 0;
int Count_0 = 0;
 
//创建栈
Stack InitStack(void){
    Stack S = (Node*)malloc(sizeof(Node));
    S->next = NULL;
    return S;
}
  
//置空栈
 void NullStack(Stack S){
    S->next = NULL;
}
 
//出栈
void Pop(Stack S){
    Stack temp = S->next;
    S->next = temp->next;
}
 
//入栈
void Push(Stack S,struct Binode c){
    Stack temp = (Node*)malloc(sizeof(Node));
    temp->ch = c;
    temp->next = S->next;
    S->next = temp;
}
 
//返回栈顶
BiTree Findhead(Stack S){
    Stack temp = S->next;
     
    return &(temp->ch);
}
 
//打印栈顶
void PrintStackTop(Stack S){
    Stack temp = S->next;
    printf("%c",temp->ch.data);
}
 
int StackEmpty(Stack S){
    if(S->next == NULL){
        /* printf("1\n"); */
        return 1;
    }else{
        /* printf("2\n"); */
        /* getchar(); */
        return 0;
    }
}
 
void print_stack(Stack S){
    Stack t = S;
    while(t){
        printf("\nt = %c\n",t->ch.data);
        t = t->next;
    }
}
 
 
//创建树
void CreatTree(BiTree *T){
    char ch;
    scanf("%c",&ch);
    //getchar();
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiTree)malloc(sizeof(Bitnode));
          
        if(!*T){
            exit(1);
        }
        (*T)->data = ch;
        //printf("ch = %c\n",ch);
        CreatTree(&(*T)->lchild);
        CreatTree(&(*T)->rchild);
    }
}
 
 
//按照前中后序打印树
void print_tree(BiTree T,int n){
    if(T == NULL){
        return;
    }
    //前序
    if( n == 1)
        printf("%c",T->data);
    print_tree(T->lchild,n);
    //中序
    if( n == 2)
        printf("%c",T->data);
    print_tree(T->rchild,n);
    //后序
    if( n == 3)
        printf("%c",T->data);
}
 
//以树的形态打印二叉树
void print_by_tree(BiTree root,int h){
    if(root == NULL){
        return;
    }
 
    print_by_tree(root->rchild,h+1);    //先打印右子树
    for(int i = 0;i < h;i++){   //层次决定结点的左右位置
        printf("  ");        
    }
    printf("%c\n",root->data);  //输出结点
 
    print_by_tree(root->lchild,h+1);
}
 
//统计结点个数
void PreOrder(BiTree root){
    if(root){
        Count++;
        if((root->lchild == NULL && root->rchild != NULL) || (root->rchild == NULL && root->lchild != NULL)){
            Count_1++;
        } 
         
        if(root->lchild != NULL && root->rchild != NULL){
            Count_2++;
        }
 
        if(root->lchild == NULL && root->rchild == NULL){
            Count_0++;
        }
         
        PreOrder(root->lchild);
        PreOrder(root->rchild);
         
 
    }
}
 
//中序输出叶子
void InOrder(BiTree root){
    if(root){
        InOrder(root->lchild);
        if(root->lchild == NULL && root->rchild == NULL){
            printf("%c",root->data);
        }
        InOrder(root->rchild);
    }
}
 
//非递归前序遍历
void Oder_qian_F(BiTree T){
    Stack S = InitStack();
    BiTree p = T;
 
    while(p != NULL || !StackEmpty(S)){
         
        while(p != NULL){
            printf("%c",p->data);
            Push(S,*p);
            p = p->lchild;
        }
        //退栈,进右子树
        if(!StackEmpty(S)){
            p = Findhead(S);
            p = p->rchild;
            Pop(S);
        }
    }
 
}
 
void Oder_zhong_F(BiTree T){
    Stack S = InitStack();
    BiTree p = T;
    while(p != NULL || !StackEmpty(S)){
        while(p != NULL){
            Push(S,*p);
            p = p->lchild;
        }
        if(!StackEmpty(S)){
            p = Findhead(S);
            printf("%c",p->data);
            p = p->rchild;
            Pop(S);
        }
    }
}
 
//非递归后序遍历
void Oder_hou_F(BiTree T){
    Stack S = InitStack();
    BiTree p = T;
    BiTree q = T;

    while(p != NULL || !StackEmpty(S)){
        while(p != NULL){
            Push(S,*p);
            p = p->lchild;
        }
 
        if(!StackEmpty(S)){
            p = Findhead(S);
            if((p->rchild == NULL) || (p->rchild->data == q->data)){
                printf("%c",p->data);
                q = p;
                p = NULL;
                Pop(S);
            }else{
                p = p->rchild;
            }
        }
    }
}
 
int main(){
    BiTree T;
    CreatTree(&T);
     
    //树状打印
    /* int h = 1; */
    /* print_by_tree(T,h); */
 
    //统计结点
    /* PreOrder(T); */
    /* printf("%d %d %d\n",Count_0,Count_1,Count_2); */
 
    //中序输出叶子
    /* InOrder(T); */
    /* printf("\n"); */
     
    //打印树
    /*
    int i;
    for(i = 1;i < 4;i++){
        print_tree(T,i);
        printf("\n");
    }*/
 
    //非递归前序遍历
    /* Oder_qian_F(T); */
    /* printf("\n"); */
     
    //非递归中序遍历
    /* Oder_zhong_F(T); */
    /* printf("\n"); */
 
    //非递归后序遍历
    Oder_hou_F(T);
    printf("\n");
 
    return 0;
}
