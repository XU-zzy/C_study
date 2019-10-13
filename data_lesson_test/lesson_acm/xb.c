#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int num;
    int passward;
    int statue;
    struct node* next;
};

int main(){
    int n,steps;
    scanf("%d %d",&n,&steps);
    getchar();
    
    int a[100];
    memset(a,0,sizeof(a));
    struct node *head,*p,*q;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    p = head;
    for(int i = 0;i < n;i++){
        scanf("%d",&p->passward);
        p->statue = 1;
        p->num = i+1;

        q = (struct node*)malloc(sizeof(struct node));
        q = p->next;
        p = q;
    }
    p->next = head;
    
    p = head;
    int sum = 0;
    printf("success\n");
    while(sum != n){
        for(int i = 1;i < steps;i++){
            while(1){
                if(p->statue == 1){
                    p = p->next;
                    break;
                }
            }
        }
        sum++;
        p->statue = 0;
        a[p->num-1] = sum;
        steps = p->passward;
    }
    
    for(int i = 0;i < n;i++){
        printf("%d\n",a[i]);
    }
}

