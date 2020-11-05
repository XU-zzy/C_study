//
// Created by zzy on 2020/11/5.
//
#include "work.h"

//phi.c
void *philosopher(void *p){
    int id = (int)p;
    while(1){
        //Thinking...
        printf("Thinking...\n");
        sleep(1);
        sem_wait(&sfork[id]);
        sem_wait(&sfork[(id+1)%5]);
        printf("Eating...\n");
        //Eating...
        sleep(1);
        sem_post(&sfork[id]);
        sem_post(&sfork[(id+1)%5]);
    }
    return NULL;
}