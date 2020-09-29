#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>

#define gettid() syscall(__NR_gettid)

pthread_t ntid;

void *printids(void *s){
    pid_t pid;
    pid_t ktid;
    pthread_t utid;

    pid = getpid();
    ktid = gettid();
    utid = pthread_self();

    printf("%s pid %u ktid %u utid %u (0x%x)\n",s,(unsigned int)pid,
            (unsigned int)ktid,(unsigned int)utid,(unsigned int)utid);
    pause();
    return NULL;
}
int main(void){

    pthread_create(&ntid,NULL,printids,"new thread:");

    printids("main thread:");
    sleep(1);
    return 0;
}
