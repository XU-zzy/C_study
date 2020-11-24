#include <stdio.h>
#include<setjmp.h>
#include<stdlib.h>

int main()
{
    jmp_buf env;
    int i;

    i = setjmp(env);

    printf("Hello world  i = %d\n",i);
    if(i!=0)
        exit(0);

    longjmp(env,2);
    printf("This line doex not get printed\n");
    return 0;
}

