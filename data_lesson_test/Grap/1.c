#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
typedef struct {
    int vex[MAXSIZE];//数据存储区  
    int front;      //头 
    int rear;       //尾 
}Queue;
 
typedef struct{
    char data;
    int in;
    int out;
}Vex;
 
typedef struct
{
    int arcs[MAXSIZE][MAXSIZE]; //顶点值 
    int visit[MAXSIZE];     //遍历标记数组 
    Vex vex[MAXSIZE];       //存顶点 
    int vexnum;             //顶点数 
    int arcnum;             //边数 
}AdjMatrix;
 
 
 
int CreatGrap(AdjMatrix *G){
    //顶点数和边数 
    scanf("%d %d",&G->vexnum,&G->arcnum);
     
    char ch_1,ch_2;
     
    //存顶点 
    getchar();
    for(int i = 0;i < G->vexnum;i++){
        scanf("%c",&G->vex[i].data);
        G->vex[i].in = 0;
        G->vex[i].out = 0;
    }
    getchar();
     
    //初始化矩阵 
    for(int i = 0;i < G->vexnum;i++){
        for(int j = 0;j < G->vexnum;j++){
            G->arcs[i][j] = 0; 
        }
    }
     
    //存储矩阵 
    for(int i = 0;i < G->arcnum;i++){
        scanf("%c%c",&ch_1,&ch_2);
        getchar();
        G->arcs[ch_1 - 'A'][ch_2 - 'A'] = 1;
         
        for(int j = 0;j < G->vexnum;j++){
            if(G->vex[j].data == ch_1){
                G->vex[j].in++;
            }
            if(G->vex[j].data == ch_2){
                G->vex[j].out++;
            }
        }
         
    }

    return 1;
}
 
//初始化遍历标记数组 
int initGrapVisit(AdjMatrix *G,int num){
    for(int i = 0;i < num;i++){
        G->visit[i] = 0;
    }
    return 1;
}
 
//深搜 
int Dfs(AdjMatrix *G,int n){
     
    printf("%c",G->vex[n].data);
    G->visit[n] = 1;
    for(int i = 0;i < G->vexnum;i++){
        if(G->visit[i] == 0 && G->arcs[n][i] == 1){
            Dfs(G,i);
        }
    }
    return 1;
}
 
int FirstAdj(AdjMatrix *G,int n){
    for(int i = 0;i <G->vexnum;i++){
        if(G->arcs[n][i] == 1 && G->visit[i] == 0){
            return i;
        }
    }
    return 0;
}
 
int NextAdj(AdjMatrix *G,int n,int w){
    for(int i = w ;i<G->vexnum;i++){
        if(G->arcs[n][i] == 1 && G->visit[i] == 0){
            return i;
        }
    }
    return 0;
}
 
//广搜 
int Bfs(AdjMatrix *G,int n){
     
    G->visit[n] = 1;
     
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    q->vex[q->front] = n;
    printf("%c",G->vex[n].data);
    while(q->front != q->rear){
         
        n = q->vex[q->front];
        q->rear++;
        int w = FirstAdj(G,n);
        while(w){
            if(!G->visit[w]){
                printf("%c",G->vex[w].data); 
                G->visit[w]=1;
                q->front++;
                q->vex[q->front] = w;
            }
            w = NextAdj(G,n,w);
        }
    }
    return 0;
}
 
int main(){
    AdjMatrix *G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    CreatGrap(G);
    int count = 0;
     
    
    for(int i = 0;i < G->vexnum;i++){
        printf("%c %d %d %d\n",G->vex[i].data,G->vex[i].in,G->vex[i].out,G->vex[i].in+G->vex[i].out);
    }
    
    //深搜遍历
    //初始化遍历数组  
    initGrapVisit(G,G->vexnum);
    for(int i = 0; i < G->vexnum;i++){
        if(!G->visit[i]){
            Dfs(G,i);
            count++;
        }
    }
    /* printf("%d",count); */
    printf("\n");
     
    
    //广搜遍历
    //初始化遍历数组 
    initGrapVisit(G,G->vexnum);
    for(int i = 0;i < G->vexnum;i++){
        if(G->visit[i] == 0){
            Bfs(G,i);
        }
    }
    printf("\n");

    return 0;   
} 
