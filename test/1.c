#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<linux/prctl.h>
 
void descendant_process(void);
 
int main(void)
{
    prctl(PR_SET_CHILD_SUBREAPER,1);
    //设置的child subreaper不会被继承
    switch(fork()){
        case 0:
            descendant_process();
            break;
        case -1:
            printf("Fork failed");
            exit(-1);
        default:
            printf("Subreaper Process:%d\n",getpid());
            sleep(10);
            /* for(;;); */
    }
    return 0;
}
 
void
descendant_process(void)
{
    switch(fork()){
        case 0:
            printf("Child process\n");
            printf("child process: %d\n", getpid());
            printf("father pid:%d\n", getppid());
            sleep(5);
            printf("now pid: %d\t ppid:%d \n",getpid(),getppid());
            break;
        case -1:
            printf("Fork failed");
            exit(-1);
        default:
            printf("Father Process\n");
            sleep(1);
            printf("Father exit\n");
            break;
    }    
    return;
}
