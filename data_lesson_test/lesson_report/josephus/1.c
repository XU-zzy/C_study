#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;   //手持密码值
    int num;    //编号
    struct node *prev;
    struct node *next;
}Jose_node;

//打印链表
void print_list(Jose_node *head,int n){
        Jose_node *p = head;
        while(n--){
            printf("data = %d,num = %d \n",p->data,p->num);
            p = p->next;
            getchar();
        }
}
//创建链表
Jose_node *Creatlist(){
    Jose_node *head = (Jose_node*)malloc(sizeof(Jose_node));
    head->data = 0;
    head->next = head;
    head->prev = head;
    return head;
}
//链表输入
int Insertlist(Jose_node *head){
    int sum,pwd;
    Jose_node *p = head;
    
    scanf("%d %d",&sum,&pwd);
    
    int n = sum;
    
    //在头后开始插入结点，所以结点 编号 为 2 
    int num = 2;

    //头的编号为1
    head->num = 1;
    //插入结点
    while(sum--){
        Jose_node *q = (Jose_node*)malloc(sizeof(Jose_node));
        scanf("%d",&p->data);
        q->num = num;
        num++;

        q->next = head;
        head->prev = q;
        p->next = q;
        q->prev = p;
        
        p = p->next;
    }

    //释放空结点
    p = head->prev;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    
    //打印链表
    /* print_list(head,n); */
    
    //返回密码值
    return pwd;
}
//约瑟夫环
void Josephus(Jose_node *head,int pwd){
    int n = 1;
    Jose_node *p = NULL;
    
    while(head){
        //与密码相同
        if(n == pwd){
            printf("%d ",head->num);
            
            //结束
            if(head->next == head){
                printf("\n");
                free(head);
                break;
            }

            //重置密码
            pwd = head->data;
            
            //释放结点
            p = head; 
            head = head->next;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            
            //从 1 开始
            n = 1;
        }else{
            //继续游戏
            head = head->next;
            n++;
        }
    }
}

int main()
{
    //创建链表
    Jose_node *head = Creatlist();
    //添加数据
    int pwd = Insertlist(head);
    //约瑟夫环
    Josephus(head,pwd);
    return 0;
}

