#include<stdio.h>
struct queue{
	int date[1000];  //储存数据
	int head;    //队首
	int tail;    //队尾
};
int main(){
	int i;
	struct queue q;
	q.head=0;
	q.tail=0;    //初始化队列
	printf("please input 9 numbers:\n");
	for (i=0;i<9;i++){
		scanf("%d",&q.date[q.tail]);
		q.tail++;
	}
	while(q.head<q.tail){
		printf("%d",q.date[q.head]); //输出队首
		q.head++;

		q.date[q.tail]=q.date[q.head]; //新队首放在队尾
		q.tail++;
		q.head++;
	}
	getchar();
	return 0;
}
