#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<linux/prctl.h>
void fun(void){
    switch(fork()){
        case -1:
            printf("Fork process 2 wrong!\n");
        case 0:
            printf("Child id: %d\n",getpid());
            printf("Parent id: %d\n",getppid());
            sleep(5);
            printf("In the end,Child id: %d\t Parent id: %d\t\n",getpid(),getppid());
            break;
        default:
            printf("Parent process\n");
            sleep(1);
            printf("Parent process exit\n");
            break;
    }
    return;
}
int main(){
    //prctl函数可以使当前调用它的进程变为subreaper进程
    /* prctl(PR_SET_CHILD_SUBREAPER,1); */
    pid_t pid;
    pid = fork();
    switch(pid){
        case -1:
            printf("Fork process 1 wrong！\n");
            exit(-1);
        case 0:
            fun();
            break;
        default:
            printf("SUBREAPER id: %d\n",getpid());
            sleep(10);
            for(;;);
    }
    return 0;
}
