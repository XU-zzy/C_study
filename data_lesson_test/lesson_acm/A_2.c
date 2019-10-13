#include<stdio.h>
#include<stdlib.h>
struct node{
    int a;
    struct node *next;
};

void print(struct node *head){
    struct node *p;
    p = head;
    while(p){
        printf("%d ",p->a);
        p = p->next;
    }
}


struct node *creatlist(int n){
   struct node *head,*p,*q;
   head = (struct node *)malloc(sizeof(struct node));
   head->next = NULL;
   q = head;

   int num;
   printf("请输入你的数据:");
   while(n--){
       p = (struct node *)malloc(sizeof(struct node));
       scanf("%d",&num);
       
       p->a = num;
       p->next = q->next;
       q->next = p;
       q = p;
   }
   head = head->next;
   return head;
}


struct node *test_A(struct node *head){
    struct node *pron,*next,*p;
    pron->next = head;
    p = head->next;
    while(p){
        if(p->a < head->a){
            
        }
    }
    return pron;
}



int main()
{
    int n;
    printf("请输入数据数量");
    scanf("%d",&n);
    struct node *head = creatlist(n);
    
    print(head);
    
    return 0;
}

