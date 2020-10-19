//多缓冲区,多生产者，多消费者，优化
//提高了效率，在同一时间内，允许一个消费者和一个生产者同时进行在缓冲区中进行操作
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#define M   8   //生产者和消费者的个数
#define N   10  //缓冲区大小
sem_t space,prod,sin,sout;

int Buffer[N];      //缓冲区
int in = 0,out = 0; //定义队头队尾

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


int main(){
    memset(Buffer,0,10);
    sem_init(&space,0,N);   //初始化缓冲区空间
    sem_init(&prod,0,0);    //初始化商品
    sem_init(&sin,0,1);     //表示队列头
    sem_init(&sout,0,1);    //表示队列尾
    pthread_t tid1[M],tid2[M];
    for(int i = 0;i < M;i++){
        pthread_create(&tid1[i],NULL,producer,NULL);
    }
    for(int i = 0;i < M;i++){
        pthread_create(&tid2[i],NULL,consumer,NULL);
    }
    sem_destroy(&space);
    sem_destroy(&prod);
    pthread_join(tid1[0],NULL);
    pthread_join(tid2[0],NULL);
    return 0;
}
