#include<pthread.h>
#include<unistd.h>
#include<sys/syscall.h>

#define gettid() syscall(__NR_gettid)

pthread_t ntid;

void *printids(void *s){
    pid_t   pid;
    pid_t   ktid;
    pthread_t utid;

    pid = getpid();
    ktid = gettid();
    utid = pthread_self;

    printf(" ")


}
