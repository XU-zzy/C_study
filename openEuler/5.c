#include<stdio.h>
int Works[20][20];
int minConsume=0;
// 给 Works和minConsume赋值
int initWorks(int workerCount)
{
    int t;
    for(int i=1;i<=workerCount;i++)
        for(int j=1;j<=workerCount;j++)
        {
            scanf("%d", &t);
            Works[i][j] = t;
            minConsume+=t;
        }
}
// 统计当前作业分配方式的消费量
int allConsume(int *N, int workerCount)
{
    int sum = 0;
    for(int i = 1;i<=workerCount;i++)
        sum+=Works[i][N[i]];
    return sum;
}
// 判断是否合法（当前工人选择的作业是否已分配给其他工人，如果已分配，返回0，否则返回1）
int isLegal(int *N, int nowWorker)
{
    for(int i=1;i<nowWorker;i++)
    {
        if(N[i]==N[nowWorker])
            return 0;
    }
    return 1;
}
// 子集树实现分配方式（穷举所有的情况）
int backTrackWorks(int *N, int workerCount, int nowWorker)
{
    //找到一种分配方式，求出该方式的总消费量
    if(nowWorker>workerCount)
    {
        int nowConsume = allConsume(N, workerCount);
        if(minConsume>nowConsume)
            minConsume = nowConsume;
        return 0;
    }
    else
    {
        for(int i=1;i<=workerCount;i++)
        {
            N[nowWorker] = i;
            if(isLegal(N, nowWorker))
            {
                backTrackWorks(N, workerCount, nowWorker+1);
            }
        }
    }
}
// workerCount 总工人数
// Works[][] 为第i个人分配工作j所需的费用为Works[i][j]
// N[] 标记已分配好的工人和该工人所做作业 例如N[1]=5,表示第一个工人选择第五个作业
// nowWorker 序号 表示当前为第nowWorker号工人分配作业
// minConsume 最小的费用
int main()
{
    int workerCount;
    scanf("%d", &workerCount);
    initWorks(workerCount);
    int N[workerCount+1];
    int nowWorker = 1;
    backTrackWorks(N, workerCount, nowWorker);
    printf("%d", minConsume);
    return 0;
}