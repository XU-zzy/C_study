//写者优先代码
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
//写者数量
#define M_w   10
//读者最多的数量
#define N_w   20
sem_t sdata,sread;
int readcount = 0;

void *reader(void *p){
    
    sem_wait(&sdata);
    sem_wait(&sread);
    sem_post(&sdata);

    printf("Reading dataset...\n");
    //Reading dataset......
//    sleep(1);
    sem_post(&sread);
    
    return NULL;
}

void *writer(void *p){
    
    sem_wait(&sdata);
    for(int i = 0;i < N_w;i++){
        sem_wait(&sread);
    }
    //Writing dataset...
    printf("Writing dataset...\n");
//    sleep(1);
    for(int i = 0;i < N_w;i++){
        sem_post(&sread);
    }

    sem_post(&sdata);

    return NULL;
}

int main(){
    sem_init(&sdata,0,1);   //数据
    sem_init(&sread,0,N_w);   //读者许可数目

    pthread_t tid1[M_w],tid2[M_w];
    for(int i = 0;i < M_w;i++){
        pthread_create(&tid1[i],NULL,writer,NULL);
    }
    for(int i = 0;i < M_w;i++){
        pthread_create(&tid2[i],NULL,reader,NULL);
    }
    sem_destroy(&sdata);
    sem_destroy(&sread);
    return 0;
}
