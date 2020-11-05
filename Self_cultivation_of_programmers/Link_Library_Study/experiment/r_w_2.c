//
// Created by zzy on 2020/11/5.
//

#include "work.h"
//写者数量
#define M_w   10
//读者最多的数量
#define N_w   20

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