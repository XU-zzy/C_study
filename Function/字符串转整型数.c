#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Convert(const char*num){
    int sum = 0;
    while(*num){
        if (*num >= '0' && *num <= '9')
            sum = sum * 10 + (*num - '0');
        num++;
    }
    return sum;
}
int main(){
    char *str;
    str = (char*)malloc(sizeof(char)*100);
    fgets(str,100,stdin);
    int res = Convert(str);
    printf("%d\n",res);
    return 0;
}
