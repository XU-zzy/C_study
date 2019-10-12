//1.输入地图基本信息；
//2.初始化队列；
//3.设置标志判断是否到达标记点；
//4.枚举四个方向，判断是否经过或有障碍物或出界；
//5.判断是否到达终点，出队，输出步数；
#include<stdio.h>
struct note {
	int x;
	int y;
	int f;	//父亲在队列中的编号
	int s;	//步数
};
int main(){
	struct note que [2501];			//假设地图长度是50 x 50
	int a[51][51]={0},book[51][51]={0};
	int i,j,k,q,p,head,tail,stx,sty,m,n;
	int tx,ty;
	int next[4][2]={{0,1},  	//向右
			{1,0},		//向下
			{0,-1},		//向左
			{-1,0}};	//向右
	printf("请输入地图大小：\n");
	scanf("%d %d",&m,&n);
	printf("请输入起点和终点坐标：\n");
	scanf("%d %d %d %d",&stx,&sty,&p,&q);
	
	printf("请输入地图：\n");
	for (i=1;i<m+1;i++){
		for(j=1;j<n+1;j++){
			scanf("%d",&a[i][j]);	//输入地图
		}
	}
	//初始化队列
	que[1].x=stx;	
        que[1].y=sty;
        que[1].f=0;
        que[1].s=0;
	head=1;
	tail=1;
	tail++;
	book[stx][sty]=1;
	int flag = 0;		//标志未到终点
	while(tail>head){
		for(k=0;k<4;k++){	//枚举四个方向
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if(tx > m || ty > n || tx<1 || ty < 1)	//判断是否越界
				continue;
			if(a[tx][ty] == 0 && book[tx][ty] == 0){//判断是否没走过，或者有无障碍物
				book[tx][ty] = 1;		//标记已经走过
				que[tail].x = tx;		//入队
				que[tail].y = ty;
				que[tail].f = head;		//因为这个点是从head中扩展出来的，所以它的父亲是head
				que[tail].s = que[head].s+1;	//计算步数
				tail++;				
			}
			if(tx == p && ty == q){			//判断是否到达终点
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
		head++;		//出队
	}
	printf("一种需要%d步",que[tail-1].s);
	getchar();
	return 0;

}
