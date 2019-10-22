#include<stdio.h>
#include<stdlib.h>
struct node {
	int a;
	int b;
	struct node *next;
};

struct node* creat(int n){
	//printf("2\n");
	struct node *p,*q,*head;
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	q = head;
	n++;
	while(n--){
		p = (struct node*)malloc(sizeof(struct node));
		//printf("2\n");
		char x,y;
		scanf("%c%d,%d%c",&x,&p->a,&p->b,&y);
		q->next = p;
		q = p;
	}
	q->next = NULL; 
	return head;
}

void print(struct node *head){
	struct node *q;
	q = head->next->next;
	while(q != NULL){
		printf("a = %d,b = %d\n",q->a,q->b);
		q = q->next;
	}
}

void sort_z(struct node *head){
	struct node *p;
	p = head->next->next;
	if(!p){
		return;
	}
	int flag = 0;
	while(p){
		if(p->a > 0 && flag != 0){
			printf("+");
		}
		
		if(p->a != 1){
			printf("%d",p->a);
			//printf("X");
			if(p->b == 1){
				printf("X");
			}
			else if(p->b != 0){
				printf("X^%d",p->b);
			}
		}else{
			if(p->a == 1){
				if(p->b == 0){
					printf("1");
				}else if(p->b ==1){
					printf("X");
				}else{
					printf("X^%d",p->b);
				}
			}
		}
		p = p->next;
		flag++;
	}
	
}
int main(){
	int n;
	scanf("%d",&n);
	
	//printf("1\n");
	struct node *head;
	head = creat(n);
	
	sort_z(head);
	
	//print(head);
	return 0;
}
