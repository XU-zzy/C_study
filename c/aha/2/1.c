#include<stdio.h>
int main(){
	int a[102]={0,6,3,1,7,5,8,9,2,4};
	int head=1;
	int tail=10;//tail指向最后一个位置
	while(head<tail){
		printf("%d",a[head]);//打印队首并出队
		head++;

		a[tail]=a[head];//新队首放到队尾
		head++;
		tail++;
	}

	getchar();getchar();
	return 0;
}

