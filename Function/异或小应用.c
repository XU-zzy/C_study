#include<stdio.h>
int main(){
    int a[9] = {1,1,2,2,5,3,3,4,4};
    int num = 0;
    
    for(int i = 0;i < 9;i++){
        num ^= a[i];
        printf("a[i] = %d  %d\n",a[i],num);
    }
    
    printf("num %d \n",num);
    return 0;
}
