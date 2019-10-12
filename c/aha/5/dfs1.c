#include<stdio.h>
int n,sum;
int e[101][101],book[51];
void dfs(int cur){
	int i;
	printf("%d ",cur);
	sum++;  //每访问一个点，sum+1
	if(sum == n)	return;  //当所有顶点都访问过了，就直接退出
	for(i = 1;i < n+1;i++){  //在cur这一行从头遍历到尾
		if (e[cur][i] == 1 && book[i] == 0){
			book[i] = 1;
			dfs(i);
		}
	}
	return;
}
int main(){
	int i,j,m,a,b;
	printf("请输入顶点总个数：\n");
	scanf("%d",&n);
	printf("请输入边数：\n");
	scanf("%d",&m);
	//初始化数组
	for (i = 1;i < n + 1;i++){
		for(j = 1;j < n + 1;j++){
			if(i == j) 
				e[i][j] = 0;   //对角线是自己连接自己，所以是边为0
			else
				e[j][j] = 999999;
		}
	}
	printf("请输入图：\n");
	for(i = 1;i < n+1;i++){
		scanf("%d %d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1;
	}
	book[1] = 1;
	dfs(1);
	return 0;
}
