//删除 data 的第 i 位数，并返回删除后的值
int deleteNum(data,i,datalen)
{
    int sum = 0;
    int n = 0;
    for(int j = 1;j<=datalen;j++)
    {
        if(i==j)
        {
            data /=10;
            continue;
        }
        sum = sum + (data%10)*Pow(10,n);
        data /=10;
        n++;
    }
    return sum;
}
//实现寻找 data 的位数函数
int Datalen(int data)
{
    int i=0;
    while(data)
    {
        data = data/10;
        i++;
    }
    return i;
}
//实现删除 n 个数的函数，子集树数实现
int DeleteFun(int data, int delCount, int datalen)
{
    if(delCount<=0)
    {
        if(min>data)
            min = data;
        return 0;
    }
    else
    {
        for(int i=1;i<=datalen;i++)
        {
            int T_data = data;
            int temdata = deleteNum(data,i,datalen);
            DeleteFun(temdata, delCount-1, datalen-1);
            data = T_data;
        }
    }
}