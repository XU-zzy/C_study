//
// Created by zzy on 2020/11/5.
//

#include "work.h"
int readcount = 0;
//r_w_2.c
void *reader(void *p){

    sem_wait(&sdata);
    sem_wait(&sread);
    sem_post(&sdata);

    //Reading dataset......
    printf("Reading dataset...\n");
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