#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int num;
}Jose_node;

int main()
{
    int sum,pwd;
    scanf("%d %d",&sum,&pwd);
    Jose_node *head = (Jose_node *)malloc(sizeof(Jose_node)*(sum+1));
    
    for(int i = 1;i <= sum;i++){
        scanf("%d",&head[i].data);
        head[i].num = i;
    }

    //下标
    int h = 1;
    //步数
    int steps = 1;
    int flag = 0;
    while(1){
        //越界
        if(h > sum){
            h = 1;
            continue;
        }
        //已被删除
        if(head[h].num == -1){
            h++;
            continue;
        }
        //当到达这个点
        if(steps == pwd){
            printf("%d ",head[h].num);
            flag++;
            if(flag == sum){
                break;
            }
            pwd = head[h].data;
            head[h].num = -1;
            steps = 1;
            h++;
            continue;
        }
        h++;
        steps++;
    }

    printf("\n");
    return 0;
}
