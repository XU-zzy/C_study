#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100

int main()
{
    
    int n,a[MAX][2],x;
    memset(a,0,sizeof(a));
    char c_1,c_2;
    scanf("%d",&n);
    getchar();
    
    for(int i = 0;i < n;i++){
        scanf("%c%d,%d%c",&c_1,&a[i][0],&a[i][1],&c_2);
    }

    scanf("%d",&x);
    
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += a[i][0]*(pow(x,a[i][1]));
    }
    printf("%d\n",sum);
}

