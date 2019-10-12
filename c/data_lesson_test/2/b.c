#include<stdio.h>
#include<stdlib.h>
struct node {
	int a;
	int b;
	struct node *next;
};

//创建链表输入
struct node* creat(int n){
	//printf("2\n");
	struct node *p,*q,*head;
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	q = head;
	n++;
    fflush(stdin);
	while(n--){
		p = (struct node*)malloc(sizeof(struct node));
		//printf("2\n");
		char x,y;
		scanf("%c%d,%d%c",&x,&p->a,&p->b,&y);
		q->next = p;
		q = p;
	}
	q->next = NULL; 
	return head->next;
}

//测试
void print_ceshi(struct node *head){
	struct node *q;
	q = head->next;
	while(q != NULL){
		printf("a = %d,b = %d\n",q->a,q->b);
		q = q->next;
	}
}

//显示
void print(struct node *head){
	
	struct node *p;
	//printf("b\n");
	p = head->next;
	//printf("s\n");
	if(!p){
        putchar('0');
        printf("\n");
		return;
	}
	int flag = 1;
	//printf("a\n");
	while(p){
		/*
        if(p->a == 0){
            p = p->next;
            continue;
        }
        */
        
        if(p->a > 0 && flag != 1){
			printf("+");
		}
		
		/*if(p->a == 0){
			p = p->next;
			continue;
		}*/
		
		if(p->a != 1 && p->a != -1){
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
			if(p->a == -1){
				if(!p->b){
					printf("-1");
				}else if(p->b == 1){
					printf("-X");
				}else{
					printf("-X^%d",p->b);
				}
			}
		}
		p = p->next;
		flag++;
	}
    printf("\n");
}

//加法 
struct node * plus (struct node* head_1,struct node* head_2){
    struct node *head,*p,*q;

    p = (struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    head = p;

    while(head_1 != NULL && head_2 != NULL){
        q = (struct node *)malloc(sizeof(struct node));

        if(head_1->b < head_2->b){  //比较指数
            q->b = head_1->b;
            q->a = head_1->a;

            head_1 = head_1->next;
        }else if(head_1->b == head_2->b){   //相加
            q->b = head_1->b;
            q->a = head_1->a + head_2->a;

            /* printf("a_1 = %d,b_1 = %d\n",head_1->a,head_2->a); */
            head_1 = head_1->next;
            head_2 = head_2->next;
        }else{
            q->b = head_2->b;
            q->a = head_2->a;

            head_2 = head_2->next;
        }
        
        if(q->a != 0){
            q->next = p->next;
            p->next = q;
            p = q;
            /* printf("a_1 = %d,b_1 = %d\n",q->a,q->b); */
        }
        else{
            free(q);
        }
        /* printf("a_1 = %d,b_1 = %d\n",q->a,q->b); */
    }


    //剩余结点插入
    while(head_1 != NULL){
        q = (struct node *)malloc(sizeof(struct node));

        q->a = head_1->a;
        q->b = head_1->b;
        q->next = p->next;
        p->next = q;
        p = q;

        head_1 = head_1->next;
        /* printf("a_2 = %d,b_2 = %d\n",q->a,q->b); */
    }

    while(head_2 != NULL){
        q = (struct node *)malloc(sizeof(struct node));

        q->a = head_2->a;
        q->b = head_2->b;
        q->next = p->next;
        p->next = q;
        p = q;

        head_2 = head_2->next;
        /* printf("a_3 = %d,b_3 = %d\n",q->a,q->b); */
    }
    
    return head;
}

//减法
struct node* sub(struct node *head_1,struct node *head_2){
    struct node *p = head_2,*head;
    
    while(p){
        p->a *= -1;
        p = p->next;
    }

    head = plus(head_1,head_2);

    return head;
}

//乘法
struct node* mul(struct node *head_1,struct node *head_2){
    struct node *pa,*pb,*head,*p,*q;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    q = head;
    
    pa = head_1;
    while(pa != NULL){
        pb = head_2;
        while(pb != NULL){
            p = (struct node*)malloc(sizeof(struct node));

            p->a = pa->a * pb->a;
            p->b = pa->b + pb->b;

            if(p->a != 0){
                p->next = q->next;
                q->next = p;
                q = p;
            }

            pb = pb->next;
        }

        pa = pa->next;
    }

    return head;
}


void destory(struct node *head){
    struct node *p = head;
    while(p){
        head = p; 
        p = p->next;
        free(head);
    }
}
int main(){
	struct node *head,*head_1,*q,*head_2;
	int n_1;
	scanf("%d",&n_1);
	
    
    //创建链表输入
    head_1 = creat(n_1);
	//printf("1\n");
	
	int n_2;
	scanf("%d",&n_2);
	head_2 = creat(n_2);
	
    //加法
	head = plus(head_1->next,head_2->next); 
	
    //减法
    /* head = sub(head_1->next,head_2->next); */

    //乘法
    head = mul(head_1->next,head_2->next);

	//printf("3\n");
	//显示
    print(head);
	
	/* print_ceshi(head_1); */
	/* print_ceshi(head_2); */
	destory(head_1);
    
    return 0;
}

