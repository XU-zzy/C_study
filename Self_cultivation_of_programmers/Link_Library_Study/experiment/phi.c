//
// Created by zzy on 2020/11/5.
//

#include "work.h"
//#define M 5
//sem_t sfork[5];

int main(){
    for(int i = 0;i < 5;i ++){
        sem_init(&sfork[i],0,1);
    }

    pthread_t tid[5];

    for(int i = 0;i < 5;i++){
        pthread_create(&tid[i],NULL,philosopher,(void *)i);
    }
    for(int i = 0;i < M;i++){
        sem_destroy(&sfork);
    }

    pthread_join(tid[0],NULL);

    return 0;
}