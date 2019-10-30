#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

//树结点
typedef struct Bitnode{
    char data;
    int ceng;
    int flag;
    struct Bitnode *lchild;
    struct Bitnode *rchild;
}Bitnode,*BiTree;
 
//链栈结点
typedef struct stack{
    struct Bitnode ch;                                                 
    struct stack *next;
}Node;

//链栈
typedef Node *Stack;
//链队列
typedef Node *Queue;

//结点总数目
int Count = 0;
//一元结点数目
int Count_1 = 0;
//二元结点数目
int Count_2 = 0;
//叶子结点数目
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
void Push(Stack S,struct Bitnode c){
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

//检验栈是否为空
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

//打印栈
void print_stack(Stack S){
    Stack t = S;
    while(t){
        printf("\nt = %c %d\n",t->ch.data,t->ch.data);
        t = t->next;
    }
}

//==============================================================
//创建队列
Queue InitQueue(){
    Queue p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    return p;
}

//添加元素
void EnterQueue(Queue q,struct Bitnode c){
    

    Queue tmp = q;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    Queue p = (Node*)malloc(sizeof(Node));
    p->ch = c;
    p->next = NULL;

    tmp->next = p;
}

//出队列
BiTree DeleteQueue(Queue q){
    Queue tmp = q->next;
    q->next = tmp->next;
    return &(tmp->ch);
}

//判断队列是否为空
int QueueEmpty(Queue q){
    if(q->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

//打印队列
void print_Queue(Queue q){
    printf("Queue:\n");
    while(q->next != NULL){
        printf("%c %d\n",q->next->ch.data,q->next->ch.data);
        q = q->next;
        /* getchar(); */
    }
}

//=========================================================

//创建树
void CreatTree(BiTree *T,int num){
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
        (*T)->ceng = ++num;
        (*T)->flag = 0;
        //printf("ch = %c\n",ch);
        CreatTree(&(*T)->lchild,num);
        CreatTree(&(*T)->rchild,num);
        num--;
    }
}

//输入的层数,求所在层叶子结点个数
int quesion;
int ans = 0;
//某层叶子节点个数
//按照前中后序打印树
void print_tree(BiTree T,int n){
    if(T == NULL){
        return;
    }
    
    if(n == 5){
        if((T->ceng == quesion) && (T->lchild == NULL) && (T->rchild == NULL) && !T->flag){
            ans++;
            T->flag = 1;
        }
        print_tree(T->lchild,n);
        print_tree(T->rchild,n);
    }

    //打印结点及其所在层
    if( n == 4){                                                                                                          
        printf("(%c,%d)",T->data,T->ceng);                                                                                
        print_tree(T->lchild,n);                                                                                          
        print_tree(T->rchild,n);                                                                                          
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

//非递归中序遍历
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
    BiTree q = NULL;
    
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

//层序遍历
void Oder_ceng(BiTree T){
    Queue q = InitQueue();
    BiTree tmp;
    //根节点入队
    EnterQueue(q,*T);
    while(!QueueEmpty(q)){
        tmp = DeleteQueue(q);
        printf("%c",tmp->data);
        if(tmp->lchild != NULL){
            EnterQueue(q,*tmp->lchild);
        }
        if(tmp->rchild != NULL){
            EnterQueue(q,*tmp->rchild);
        }
    }
}

char str_qian[100];
char str_zhong[100];
char str_hou[100];
//按照前序和中序遍历结果来创建二叉树
BiTree Creat_Tree_by_qian_zhong(char *qian,char *zhong,int len_qian){
    if(!len_qian){
        return NULL;
    }
    
    //根
    BiTree T = (BiTree)malloc(sizeof(Bitnode));
    T->data = qian[0];
    
    //在中序中找根
    char *p = strchr(zhong,qian[0]);

    //左子树长度
    int len = p - zhong;

    //开始创建
    T->lchild = Creat_Tree_by_qian_zhong(qian + 1,zhong,len);
    T->rchild = Creat_Tree_by_qian_zhong(qian + 1 + len,p + 1,len_qian - len - 1);

    return T;
}

//按照中序和前序遍历结果来创建二叉树
BiTree Creat_Tree_by_zhong_hou(char *hou,char *zhong,int len_hou){
    if(!len_hou){
        return NULL;
    }
    
    BiTree T = (BiTree)malloc(sizeof(Bitnode));
    T->data = hou[len_hou-1];
    
    /* printf("%c\n",T->data); */
    /* getchar(); */
    //在中序中寻找根
    char *p = strchr(zhong,hou[len_hou - 1]);

    //计算左子树长度
    int len = p - zhong;

    //开始创建
    T->lchild = Creat_Tree_by_zhong_hou(hou,zhong,len);
    T->rchild = Creat_Tree_by_zhong_hou(hou + len,p + 1,len_hou - len - 1);

    return T;
}

void swap(BiTree *l,BiTree *r){
    BiTree tmp;
    tmp = *l;
    *l = *r;
    *r = tmp;
}

//交换左右子树
BiTree ChangeLeftRightChild(BiTree T){
    if(T == NULL){
        return NULL;
    }
    
    //交换指针
    swap(&(T->lchild),&(T->rchild));

    ChangeLeftRightChild(T->lchild);
    ChangeLeftRightChild(T->rchild);
    return T;
}

//寻找共同祖先
BiTree Get_Same_Parent(BiTree T,BiTree node_1,BiTree node_2){

    if(T == NULL || node_1 == NULL || node_2 == NULL){
        return NULL;
    }
    
    if(T->data == node_1->data || T->data == node_2->data){
        return T;
    }

    BiTree left = Get_Same_Parent(T->lchild,node_1,node_2);
    BiTree right = Get_Same_Parent(T->rchild,node_1,node_2);

    if(left != NULL && right != NULL){
        return T;
    }

    if(left == NULL){
        if(right != NULL)
        printf("right %c\n",right->data);
        return right;
    }else{
        if(left != NULL)
        printf("left %c\n",left->data);
        return left;
    }
}

int main(){
    BiTree T;
    
    //创建一个二叉树
    //层数
    int num = 0;
    CreatTree(&T,num);
    
    getchar();
    //寻找最近共同祖先
    BiTree node_1 = (BiTree)malloc(sizeof(Bitnode));
    BiTree node_2 = (BiTree)malloc(sizeof(Bitnode));
    
    char ch,a[10];
    int i = 0;
    while((ch = getchar()) != '\n'){
        if(ch == ' '){
            continue;
        }
        a[i] = ch;
        i++;
    }
    node_1->data = a[0];
    node_2->data = a[2];

    BiTree parent = Get_Same_Parent(T,node_1,node_2);
    printf("sss\n");
    /* getchar(); */
    if(parent != NULL)
    printf("%c\n",parent->data);

    /*
    //交换左右子树
    T = ChangeLeftRightChild(T);
    for(int i = 1;i < 4;i++){
        print_tree(T,i);
        printf("\n");
    }
    */

    /*
    //按照前序和中序遍历序列创建二叉树
    scanf("%s%s",str_qian,str_zhong);
    T = Creat_Tree_by_qian_zhong(str_qian,str_zhong,strlen(str_qian));
    print_tree(T,3);
    printf("\n");
    */
    //按照中序和后序遍历序列创建二叉树
    /*scanf("%s%s",str_zhong,str_hou);
    T = Creat_Tree_by_zhong_hou(str_hou,str_zhong,strlen(str_hou));
    print_tree(T,1);    
    printf("\n");
    */

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
    /* Oder_hou_F(T); */
    /* printf("\n"); */

    //层序遍历
    /* Oder_ceng(T); */
    /* printf("\n"); */
    
    //输出结点和其所在层
    /* print_tree(T,4); */
    /* printf("\n"); */

    //计算某层叶子结点个数
    /*scanf("%d",&quesion);
    print_tree(T,5);
    printf("%d\n",ans);
    */

    return 0;
}
