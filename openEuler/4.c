#include <stdio.h>
#include <stdlib.h>

int sum=0;
int findFlage = 0;
int saveNum = 0;

int sumSet(int *saveSet)
{
    int s = 0;
    for(int i = 1; i<=saveNum; i++)
        s+=saveSet[i];
    return s;
}

int backTrack(int *Set, int setNum, int *saveSet, int nowPlace)
{
    //是否找到
    if(sumSet(saveSet) == sum)
    {
        //找到并标记
        findFlage = 1;
        return 0;
    }
    else
    {
        for(int i = nowPlace; i <= setNum; i++)
        {
            saveNum++;
            saveSet[saveNum] = Set[i];
            //总和小于 c
            if(sumSet(saveSet)<=sum && findFlage == 0)
            {
                //注意：这里容易重复。
                //backTrack(Set, setNum, saveSet, nowPlace+1);
                backTrack(Set, setNum, saveSet, i+1);
            }

            if(findFlage == 1)
                return 0;
            saveSet[saveNum] = 0;
            saveNum--;
        }
    }
}

int main()
{
    int setNum;
    int c;
    scanf("%d %d", &setNum, &c);

    sum = c;
    int Set[setNum+1];

    int saveSet[setNum+1];
    for(int i = 1;i<=setNum;i++)
        scanf("%d", &Set[i]);

    backTrack(Set, setNum, saveSet, 1);

    if(findFlage == 0){
        printf("No Solution!");
    }
    else{
        for(int i = 1;i<=saveNum;i++)
            printf("%d ", saveSet[i]);
    }

}