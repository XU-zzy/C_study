#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct pos
{
    int x;
    int y;
    int dir;
};
 
const int MAX = 10000;
int flag = 0;
vector < pos> v;
int dir[5][2] = { {0,0},{0,1},{1,0},{0,-1},{-1,0} };// 1 2 3 4 
int n,m;
string mp[MAX];//存储地图
int vis[MAX][MAX];//记录是否走过
 
bool judge(int x,int y){
    if(x <= n && x >= 1 && y <= m && y >= 1 && vis[x][y] == 0 && mp[x][y] == '0')
        return true;
    else 
        return false;
}
 
void dfs(int x,int y){
    if(x == n && y == m){//找到递归出口
        pos p;
        p.x = x;
        p.y = y;
        p.dir = 0;
        flag = 1;
        v.push_back(p);
        return ;
    }
 
    //试探四个方向
    for(int i = 1;i<5;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(judge(nx,ny)){
            pos p;
            p.x = x;
            p.y = y;
            p.dir = i;
            v.push_back(p);
            vis[nx][ny] = 1;
             
            dfs(nx,ny);
             
            if(!flag)
                v.pop_back();
            else return;
            vis[nx][ny] = 0;
        }
    }
 
    return ;//无解
}
 
int main(){
    cin >> n >> m;
     
    for(int i = 1;i<=n;i++){
            cin >> mp[i];
            mp[i] = " " + mp[i];
    }
 
    vis[1][1] = 1;
    dfs(1,1);
     
    if(flag){
        int size = v.size();
        for(int i = 0;i<size;i++){
            printf("(%d,%d,%d)",v[i].x,v[i].y,v[i].dir);
        }
    }else{
        cout << "NO" << endl;
    }
 
    return 0;
}

