#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define WALL 0
#define ROUTE 1          //墙为0，路为1
#define VISITED 9       //该位置已经被访问 
typedef struct stack{
	int arr[1111][2];
	int top;
}*Stack;
Stack Create();
int isEmpty(Stack s);
int isFull(Stack s);
int pop(Stack s,int *i,int *j);
int push(Stack s,int i,int j);                //栈结构及其操作 
//
int L = 34;         //设定迷宫长度
void initMaze(int **maze,int x,int y);            //深度优先算法生成迷宫 
void solve(int **maze,int x,int y,int dx,int dy);      //传入迷宫，迷宫入口，及迷宫出口 
int main()
{
	srand((unsigned)time(NULL));
	int dx,dy;
	int **maze = (int**)malloc(L* sizeof(int *));
	for(int i=0; i < L; i++){
		maze[i] = (int*)calloc(L,sizeof(int));
	}          //申请一个二位数组，长为L,宽为L
	//初始化数组
	for(int i = 0; i < L; i++){
		for(int j = 0;j< L;j++){
			maze[i][j] = WALL;
		}
	}
	for(int i = 0; i < L; i++){
		maze[i][0] = ROUTE;
		maze[0][i] = ROUTE;
		maze[L-1][i] = ROUTE;
		maze[i][L-1] = ROUTE;
	}                 //使(L-4)*(L-4)的迷宫外侧有一层路,而且第二层的墙不能挖
	initMaze(maze,2,2);        //设定第二个为入口
	maze[2][1] = ROUTE;
	//寻找出口
	for(int i = 2;i<L-2;i++){
		if(maze[i][L-3] == ROUTE){
			maze[i][L-2] = ROUTE;
			dx = i;
			dy = L-2;
			break;
		}
	} 
	for(int i = 0; i < L; i++){
		for(int j = 0; j < L; j++){
			if(maze[i][j]==WALL){
				printf("0");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	solve(maze,2,1,dx,dy);
}

//生成迷宫
void initMaze(int **maze,int x,int y)
{
	maze[x][y] = ROUTE;
	int directions[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
	for(int i = 0; i < 4;i++){
		int r = rand()%4;
		int temp;
		temp = directions[0][0];
		directions[0][0] = directions[r][0];
		directions[r][0] = temp;
		
		temp = directions[0][1];
		directions[0][1] = directions[r][1];
		directions[r][1] = temp;
	} //在每次调用init函数时，四个方向随机
	for(int i = 0; i < 4; i++){
		int dx = x;
		int dy = y;
		int pace = 1;
		while(pace>0){ 
			dx += directions[i][0];
			dy += directions[i][1];
			//避免当前(dx,dy)为ROUTE 
			if(maze[dx][dy]==ROUTE){
				break;
			}
			int count = 0;
			//判断(dx,dy)上下左右有没有1，没有1则可以继续走,但是要去掉来时的1 
			for(int j = dx-1;j<dx+2;j++){
				for(int k=dy-1;k<dy+2;k++){
					if(abs(j-dx)+abs(k-dy)==1&&maze[j][k]==ROUTE){
						count++;
					}
				}
			}
			if(count>1){
				break;
			}
			pace--;
			maze[dx][dy] = ROUTE;
		}
		//如果break了，则不向下进行 
		if(pace <= 0){
			initMaze(maze,dx,dy);
		}
	}	
} 
void solve(int **maze,int x,int y,int dx,int dy)
{
	Stack s = Create();
	int directions[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
	//1.判断当前节点周围是否有ROUTE，同时记录下当前节点已经被访问过 
	//	没有ROUTE则pop出栈 
	// 	有ROUTE则将此节点放入栈,然后将ROUTE当成节点，继续进行1 
	//一直遇到(dx,dy)节点后，跳出 
	while(!(x==dx&&y==dy)){
		maze[x][y] = VISITED;
		int count = 0;
		for(int i = x-1;i<x+2;i++){
			for(int j = y-1;j<y+2;j++){
				if(abs(i-x)+abs(j-y)==1&&maze[i][j]==ROUTE){
					count++;
				}
			}
		}
		//去除边界的影响 
		if(x<1||x>L-2||y<1||y>L-2){
			count = 0;
		}
		if(count>0){
			for(int i = 0; i < 4;i++){
				int tempX = x + directions[i][0];
				int tempY = y + directions[i][1];
				if(maze[tempX][tempY]==ROUTE){
					push(s,x,y);
					x = tempX;
					y = tempY;
					break; 
				}
			}
			
		}else{
			pop(s,&x,&y);
		}
	}
	for(int i = 1; i <= s->top;i++){
        printf("%5d-%-5d",s->arr[i][0],s->arr[i][1]);
        if(i%10 == 0 && i != 0){
            printf("\n");
        }
	}
    printf("\n");
}


//栈操作函数
Stack Create()
{
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->top = -1;
	return s;	
}
//创建
//判空
int isEmpty(Stack s)
{
	if(s->top<=-1){
		return 1;
	}	
	return 0;
}
//判满
int isFull(Stack s)
{
	if(s->top>=1110){
		return 1;
	}
	return 0;	
}
//push操作 
int push(Stack s,int i,int j)
{
	if(isFull(s)){
		return 0;
	}
	s->top++;
	s->arr[s->top][0] = i;
	s->arr[s->top][1] = j;
	return 1;	
} 
//pop操作 
int pop(Stack s,int *i,int *j)
{
	if(isEmpty(s)){
		return 0;
	}
	*i = s->arr[s->top][0];
	*j = s->arr[s->top][1];
	s->top--;
	return 1;
}
