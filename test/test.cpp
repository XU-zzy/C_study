//公交车最多可以运输多少人
//从左上角到右下角
//只能走右、下
#include <iostream>
#include <queue>
#include <stdio.h>

#define N 9
using namespace std;

struct point{
    int x;
    int y;
    int people;
};

int Bfs(int st ,int ed,int map[N][N]){
    queue<point> qu;

    point start,end,u,t;
    start.x = 0,start.y = 0,start.people = st;
    end.x = 0,end.y = 0,end.people = ed;
    
    int peps = start.people; 

    qu.push(start);

    while(!qu.empty()){
        u = qu.front();
        qu.pop();

        if((u.x == N - 1) && (u.y == N - 1)){
            return peps;
        }

        //向左
        if((u.x+1) < N){
            t.x = u.x + 1;
            t.y = u.y;
            t.people = u.people + map[t.x][t.y];
            if(t.people > peps){
                peps = t.people;
            }
            qu.push(t);
            t.x -= 1;
        }
        //向下
        if((u.x+1) < N){
            t.y = u.y + 1;
            t.people = u.people + map[t.x][t.y];
            if(t.people > peps){
                peps = t.people;
            }
            qu.push(t);
        }
    }
    return peps;
}

int main()
{
    int map[N][N] = { {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 1, 0, 0, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int ans = Bfs(map[0][0],map[N-1][N-1],map);
    
    std::cout << ans << std::endl;
    return 0;
}
