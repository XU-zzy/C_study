#include<stdio.h>
int a[51][51],min=999999,book[10000];
int m;
void dfs(int cur,int s){
	int k;
	if(min < s)	return;
	if(cur == m){
		if(s < min) min=s;//更新最小值
		return;
	}
	for(k = 1;k < m+1;k++){
		if(a[cur][k] != 999999 && book[k] == 0){
			book[k] = 1;
			dfs(k,s + a[cur][k]);
			book[k] = 0;
		}
	}
	return;
}
int main(){
	int i,j,n,c,r,s1;
	printf("请输入城市和公路的个数：\n");
	scanf("%d %d",&m,&n);
	printf("请输入图：\n");
	for(i = 1;i < m + 1;i++){
		for(j = 1;j < m + 1;j++){
			if (i == j) 
				a[i][j] = 0;
			else
				a[i][j] = 999999;
		}
	}

	for(i = 1;i < n+1;i++){
		scanf("%d %d %d",&c,&r,&s1);
		a[c][r] = s1;
	}
	book[1] = 1;
	dfs(1,0);
	printf("%d",min);
	return 0;
}
