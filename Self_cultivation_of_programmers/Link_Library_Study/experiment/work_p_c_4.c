//
// Created by zzy on 2020/11/5.
//

#include "work.h"
int in = 0,out = 0; //定义队头队尾

//pro_con_4.c
void *producer(void *p){
    while(1){
        sem_wait(&space);
        sem_wait(&sin);
        printf("Put a produt into Buffer[%d]\n",in);
        Buffer[in] = 1;
        printf("Buffer[%d] = %d\n",in,Buffer[in]);
        in = (in + 1)%N;
        sleep(1);
        sem_post(&prod);
        sem_post(&sin);
    }
    return NULL;
}

void *consumer(void *p){
    while(1){
        //下面两条语句不可交换位置，否则发生死锁
        //若交换，
        sem_wait(&prod);
        sem_wait(&sout);
        printf("Gets a produt from Buffer[%d]\n",out);
        Buffer[out] = 0;
        printf("Buffer[%d] = %d\n",out,Buffer[out]);
        out = (out + 1)%N;
        sleep(1);
        sem_post(&space);
        sem_post(&sout);
    }
    return NULL;
}