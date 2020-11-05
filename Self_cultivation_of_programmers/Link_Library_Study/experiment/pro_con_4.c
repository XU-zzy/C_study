//
// Created by zzy on 2020/11/5.
//
#include "work.h"

int main(){
    memset(Buffer,0,10);
    sem_init(&space,0,N);   //初始化缓冲区空间
    sem_init(&prod,0,0);    //初始化商品
    sem_init(&sin,0,1);     //表示队列头
    sem_init(&sout,0,1);    //表示队列尾
    pthread_t tid1[M_p],tid2[M_p];
    for(int i = 0;i < M_p;i++){
        pthread_create(&tid1[i],NULL,producer,NULL);
    }
    for(int i = 0;i < M_p;i++){
        pthread_create(&tid2[i],NULL,consumer,NULL);
    }
    sem_destroy(&space);
    sem_destroy(&prod);
    pthread_join(tid1[0],NULL);
    pthread_join(tid2[0],NULL);
    return 0;
}