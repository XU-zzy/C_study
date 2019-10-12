//1.定义全局变量；
//2.dfs()函数，判断是否到达N+1个盒子前，输出排列，计算多少种情况；
//3.按照顺序一一放牌，用book判断牌是否在手上;
//4.dfs()递归；
//5.收回牌；
#include<stdio.h>
int a[10],book[10],n;         
int sum=0;			//定义全剧变量
void dfs (int steps){   	//表示站在第几个盒子前
	int i;
	if (steps == n+1){	//如果已经站在了N+1个盒子前，说明已经方完，可以输出一种结果
		for (i=1;i<n+1;i++)
			printf("%d ",a[i]);
		sum++;		//计算有多少种情况
		printf("\n");
		
		return;		//返回之前的一步（最近一次调用dfs的地方）
	}
	//此时站在第steps个盒子前，判断放哪一张牌
	for(i=1;i<n+1;i++){	//按照顺序一一尝试
		if(book[i] == 0){	//判断i是否还在手上
			a[steps] = i;	
			book[i] = 1;	//设置为1，即已经不再手上

			dfs(steps + 1);
			book[i] = 0;	//十分重要的一步，一定要将刚才尝试的扑克牌收回，才能进行下一次尝试
		}
	}

	return;
}
int main(){
	printf("请输入有多少张牌（不大于9张）：\n");
	scanf("%d",&n);
	dfs(1);			//首先站在1号盒子面前
	printf("一共有%d种情况",sum);
	getchar();
	return 0;
}
