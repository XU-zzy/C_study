#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define WALL 0
#define ROUTE 1          //ǽΪ0��·Ϊ1
#define VISITED 9       //��λ���Ѿ������� 
typedef struct stack{
	int arr[1111][2];
	int top;
}*Stack;
Stack Create();
int isEmpty(Stack s);
int isFull(Stack s);
int pop(Stack s,int *i,int *j);
int push(Stack s,int i,int j);                //ջ�ṹ������� 
//
int L = 34;         //�趨�Թ�����
void initMaze(int **maze,int x,int y);            //��������㷨�����Թ� 
void solve(int **maze,int x,int y,int dx,int dy);      //�����Թ����Թ���ڣ����Թ����� 
int main()
{
	srand((unsigned)time(NULL));
	int dx,dy;
	int **maze = (int**)malloc(L* sizeof(int *));
	for(int i=0; i < L; i++){
		maze[i] = (int*)calloc(L,sizeof(int));
	}          //����һ����λ���飬��ΪL,��ΪL
	//��ʼ������
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
	}                 //ʹ(L-4)*(L-4)���Թ������һ��·,���ҵڶ����ǽ������
	initMaze(maze,2,2);        //�趨�ڶ���Ϊ���
	maze[2][1] = ROUTE;
	//Ѱ�ҳ���
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

//�����Թ�
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
	} //��ÿ�ε���init����ʱ���ĸ��������
	for(int i = 0; i < 4; i++){
		int dx = x;
		int dy = y;
		int pace = 1;
		while(pace>0){ 
			dx += directions[i][0];
			dy += directions[i][1];
			//���⵱ǰ(dx,dy)ΪROUTE 
			if(maze[dx][dy]==ROUTE){
				break;
			}
			int count = 0;
			//�ж�(dx,dy)����������û��1��û��1����Լ�����,����Ҫȥ����ʱ��1 
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
		//���break�ˣ������½��� 
		if(pace <= 0){
			initMaze(maze,dx,dy);
		}
	}	
} 
void solve(int **maze,int x,int y,int dx,int dy)
{
	Stack s = Create();
	int directions[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
	//1.�жϵ�ǰ�ڵ���Χ�Ƿ���ROUTE��ͬʱ��¼�µ�ǰ�ڵ��Ѿ������ʹ� 
	//	û��ROUTE��pop��ջ 
	// 	��ROUTE�򽫴˽ڵ����ջ,Ȼ��ROUTE���ɽڵ㣬��������1 
	//һֱ����(dx,dy)�ڵ������ 
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
		//ȥ���߽��Ӱ�� 
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


//ջ��������
Stack Create()
{
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->top = -1;
	return s;	
}
//����
//�п�
int isEmpty(Stack s)
{
	if(s->top<=-1){
		return 1;
	}	
	return 0;
}
//����
int isFull(Stack s)
{
	if(s->top>=1110){
		return 1;
	}
	return 0;	
}
//push���� 
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
//pop���� 
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
