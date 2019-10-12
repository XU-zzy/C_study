#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *fun (char a[],int n){
    unsigned int i,j;
    int t;
    i = 0;
    j = n;
    while (i < j){
        while(a[i] % 2 != 0)
            i++;
        while(a[j] % 2 != 0)
            j--;
        if (i < j){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    return a;
}
