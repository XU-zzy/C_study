//测试用例：
//10 10
//1 2 1 0 0 0 0 0 2 3
//3 0 2 0 1 2 1 0 1 2
//4 0 1 0 1 2 3 2 0 1
//3 2 0 0 0 1 2 4 0 0
//0 0 0 0 0 0 1 5 3 0
//0 1 2 1 0 1 5 4 3 0
//0 1 2 3 1 3 6 2 1 0
//0 0 3 4 8 9 7 5 0 0
//0 0 0 3 7 8 6 0 1 2
//0 0 0 0 0 0 0 0 1 0
#include<stdio.h>
int a[51][51],num = 0,m,n,sum;
int book[51][51];
void dfs(int x,int y,int color){
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	a[x][y] = color;	//给该点着色
	for (k = 0;k < 4;k++){
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx > m || tx < 1 || ty > n || ty < 1)
			continue;

		if (a[tx][ty] > 0 && book[tx][ty] == 0){
		        sum++;	//不清楚！！！
			book[tx][ty] = 1;
			dfs(tx,ty,color);	
		}
	}
	return;
}
int main(){
	int i,j,num = 0;;
	printf("请输入地图的长，宽：\n");
	scanf("%d %d",&m,&n);
	printf("请输入地图：\n");
	for(i = 1;i < m+1;i++)
		for (j = 1;j < n+1;j++)
			scanf("%d",&a[i][j]);
	for(i = 1;i < m+1;i++){			
		for(j = 1;j < n+1;j++){
			if(a[i][j] > 0){
				num--;		//每个点不同颜色，并记录岛的数量
				book[i][j] = 1;
				dfs(i,j,num);
			}
		}
	}
	printf("%d %d\n",-num,sum);
	
	for(i = 1;i < m+1; i++){
		for(j = 1;j < n+1;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
	getchar();
}
