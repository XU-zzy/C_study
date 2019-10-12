#include <stdio.h>
int Check_key()
{
    int i=1;
    //将int型的i强转为char型
    return *(char *)&i;
}
 
int main()
{
    int ret=Check_key();
    if(ret==1)
        printf("小端\n");
    else
        printf("大端\n");
    return 0;
}
