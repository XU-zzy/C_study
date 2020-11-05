//单缓冲区，单生产者，单消费者问题
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t space,prod;

void *producer(void *p){
    while(1){
        sem_wait(&space);
        printf("Put a produt\n");
        sleep(1);
        sem_post(&prod);
    }
    return NULL;
}

void *consumer(void *p){
    while(1){
        sem_wait(&prod);
        sleep(1);
        printf("Gets a produt\n");
        sem_post(&space);
    }
    return NULL;
}


int main(){
    sem_init(&space,0,1);   //初始化缓冲区空间
    sem_init(&prod,0,0);    //初始化商品
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,producer,NULL);
    pthread_create(&tid[1],NULL,consumer,NULL);
    sem_destroy(&space);
    sem_destroy(&prod);
    pthread_join(tid[0],NULL);
    return 0;
}
