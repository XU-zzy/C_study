//读者优先代码
//基本实现了“读——读允许”，“读——写互斥”，“写——写互斥”
//但是存在缺陷，当程序开始后，如果读者线程率先抢占了资源，
//之后涌入多个读者线程，同时也有写者线程
//这时写者线程会存在大量等待时间
//然而，在实际应用操作中，写者往往一般具有更高的操作优先权，需要优先执行
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
//读者和写者的数量
#define M   10
sem_t sdata,srcount;
int readcount = 0;

void *reader(void *p){
    sem_wait(&srcount);
    readcount += 1;
    if(1 == readcount){
        sem_wait(&sdata);
    }
    sem_post(&srcount);

    //Reading dataset......
    
    sem_wait(&srcount);
    readcount -= 1;
    if(0 == readcount){
        sem_post(&srcount);
    }
    sem_post(&srcount);
    return NULL;
}

void *writer(void *p){
    sem_wait(&sdata);

    //Writing dataset...
    
    sem_post(&sdata);

    return NULL;
}

int main(){
    sem_init(&sdata,0,1);   //数据
    sem_init(&srcount,0,1); //读者数量

    pthread_t tid1[M],tid2[M];
    for(int i = 0;i < M;i++){
        pthread_create(&tid1[i],NULL,writer,NULL);
    }
    for(int i = 0;i < M;i++){
        pthread_create(&tid2[i],NULL,reader,NULL);
    }
    sem_destroy(&sdata);
    sem_destroy(&srcount);
    return 0;
}
