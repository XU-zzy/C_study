#include<stdio.h>
#include<stdlib.h>
struct node{              //创建一个结构体来表示链表的结点类型
	int date;
	struct node *next;
};
int main(){
	int a,i,n;
	struct node *head,*p,*q,*t;
	printf("请输入有几个数：\n");
	scanf("%d",&n);
	head=NULL;      //头指针为空
	for(i=0;i<n;i++){   //循环读如n个数
		scanf("%d",&a);
		p=(struct node *)malloc(sizeof(struct node));   //动态申请一个空间，用来存放一个结点，并用临时指针p指向这个结点
		p->date=a;      //将数据存储到当前结点中
		p->next=NULL;   //设置当前结点的后继指针为空，也就是当前结点的下一结点为空
		if(head==NULL)
			head=p;  //如果这是第一个创建的结点，则将头指针指向该结点
		else
			q->next=p;  //如果不是，就将头指针指向这个结点
		q=p;     //指针q也指向当前结点
	}
	printf("请输入要插入的数字：\n");
	scanf("%d",&a);   //读如待插入的数
	t=head;           //从链表头开始遍历
	while(t!=NULL){   //没有达到指针尾部时循环
		if( t->next==NULL || t->next->date>a){    //如果下一个结点是最后一个结点或者下一个结点的数值大于插入数时插入
			p=(struct node *)malloc(sizeof(struct node *));
			p->date=a;
			p->next=t->next;      //新增结点后继指针指向指向当前结点的后继指针指向的结点
			t->next=p;            //当前结点的后继指针指向新增结点
			break;
		}
		t=t->next;  //继续下一结点
	}
	t=head;
	while(t!=NULL){      //输出链表中的所有数
		printf("%d ",t->date);
		t=t->next;
	}
	getchar();getchar();
	return 0;
}
