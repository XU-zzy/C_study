//多缓冲区,单生产者，单消费者
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#define N   10
sem_t space,prod;

int Buffer[N];
int in = 0,out = 0; //定义队头队尾

void *producer(void *p){
    while(1){
        sem_wait(&space);
        printf("Put a produt into Buffer[%d]\n",in);
        Buffer[in] = 1;
        printf("Buffer[%d] = %d\n",in,Buffer[in]);
        in = (in + 1)%N;
        sleep(1);
        sem_post(&prod);
    }
    return NULL;
}

void *consumer(void *p){
    while(1){
        sem_wait(&prod);
        printf("Gets a produt from Buffer[%d]\n",out);
        Buffer[out] = 0;
        printf("Buffer[%d] = %d\n",out,Buffer[out]);
        out = (out + 1)%N;
        sleep(1);
        sem_post(&space);
    }
    return NULL;
}


int main(){
    memset(Buffer,0,10);
    sem_init(&space,0,N);   //初始化缓冲区空间
    sem_init(&prod,0,0);    //初始化商品
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,producer,NULL);
    pthread_create(&tid[1],NULL,consumer,NULL);
    sem_destroy(&space);
    sem_destroy(&prod);
    pthread_join(tid[0],NULL);
    return 0;
}
