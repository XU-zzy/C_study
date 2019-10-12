//图的遍历
#include<stdio.h>
int n,sum;
int e[101][101],book[51];
int main(){
        int i,j,m,a,b;
	int head,tail,cur;
	int que[10002];
        
	printf("请输入顶点总个数：\n");
        scanf("%d",&n);
        printf("请输入边数：\n");
        scanf("%d",&m);
        //初始化数组
	for (i = 1;i < n + 1;i++){
                for(j = 1;j < n + 1;j++){
                        if(i == j)
                                e[i][j] = 0;	////对角线是自己连接自己，所以是边为0
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
	//初始化队列和标记book
	head = 1;
	tail = 1;
	que[tail] = 1;
	tail++;
	book[1] = 1;
	
	while(head < tail && tail < n+1){
		cur = que[head];	//当前正在访问的顶点编号
		for(i = 1;i < n+1;i++){ //依次尝试
			//判断从点cur到顶点i是否有边,并判断i是否已经访问过
			if (e[cur][i] == 1 && book[i] == 0){
				que[tail] = i;	//符合条件，入队
				tail++;
				book[i] = 1;
			}
			if(tail > n)	break;
		}
		head++;
	}

	for(i = 1;i < tail;i++)
		printf("%d ",que[i]);

	return 0;
}
