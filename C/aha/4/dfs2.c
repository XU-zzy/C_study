#include<stdio.h>
int m,n,p,q;
int min=99999999;
int a[51][51],book[51][51];
void dfs (int x,int y,int steps){

int next[4][2]={{-1,0},      	//向上
		 {1,0},  	//向下
		  {0,-1},   	//向左 
		   {0,1}    	//向右 
			 	};
	int tx,ty,k;
	if (x==p && y==q){		//到达终点 
		if (steps<min)
			min = steps;
		return;
	}
	
	for(k=0;k<4;k++){		//枚举四种类型 
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx > m || ty > n || tx < 1 || ty < 1)	//判断是否出界
			continue;
		if (a[tx][ty] == 0 && book[tx][ty] == 0 ){	//判断是否走过 
			book[tx][ty] = 1; 	//已经走过标记 
			dfs(tx,ty,steps+1);
			book[tx][ty] = 0;	//退一步 
		}
	}
	return;
}

int main(){
	int i,j,stx,sty;
	printf("请输入地图的长和宽：\n");
	scanf("%d %d",&m,&n);
	printf("请输入地图：\n");
	for(i=1;i<m+1;i++){
		for (j=1;j<n+1;j++){
			scanf("%d",&a[i][j]);
		}
	} 
	printf("请输入起始位置和终点：\n");
	scanf("%d %d %d %d",&stx,&sty,&p,&q);
	book[stx][sty]=1;
	dfs(stx,sty,0);
	printf("最短路径需要 %d 步\n",min);
	return 0; 
}
