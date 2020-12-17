#include<stdio.h>
#include<math.h>
int sum = 0;
void swap(int *place, int a,int b)
{
    char t;
    t = place[a];
    place[a] = place[b];
    place[b] = t;
}
// 判断当前的皇后位置是否合法
int isLegal(int *place, int nowQueen)
{
    for(int i=1;i<nowQueen;i++)
    {
        if( (abs(nowQueen-i) == abs(place[nowQueen]-place[i])) || place[nowQueen] == place[i])
            return 0;
    }
    return 1;
}
// 排列数树实现n皇后函数（穷举）
// nowQueen 序号 为当前第nowQueen号的皇后寻找位置
int backTrack(int *place, int queenCount, int nowQueen)
{
    if(nowQueen>queenCount)
    {
        sum++;
        return 0;
    }
    else
    {
        for(int i=nowQueen;i<=queenCount;i++)
        {
            swap(place, nowQueen, i);
            if(isLegal(place, nowQueen))
            {
                backTrack(place, queenCount, nowQueen+1);
            }
            swap(place, nowQueen, i);
        }
    }
}
// queenCount 皇后的总个数
// place[] 标记已经有位置的皇后， 例如place[3] = 5, 表示第3号皇后的位置是第3行第5列
// place[] 的下标有两个作用，表示第i号皇后和该皇后在第i行
// sum 统计所有情况
int main()
{
    int queenCount;
    scanf("%d", &queenCount);
    int place[queenCount+1];
    for(int i = 1;i<=queenCount;i++)
        place[i] = i;
    //从第一个皇后开始
    backTrack(place, queenCount, 1);
    printf("%d", sum);
    return 0;
}