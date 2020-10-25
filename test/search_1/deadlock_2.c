//生产者——消费者死锁
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;

static int goods = 0;

void *producer (void *pos){
    printf("producer start\n");
    while(1){
        pthread_mutex_lock(&mutexA);
        goods++;
        printf("goods+1\n");
        sleep(1);
        pthread_mutex_lock(&mutexB);
       
        pthread_mutex_unlock(&mutexA);
        
        pthread_mutex_unlock(&mutexB);
    }
    return NULL;
}

void *customer (void *pos){
    printf("customer start\n");
    while(1){
        pthread_mutex_lock(&mutexB);
        goods--;
        printf("goods-1\n");
        sleep(1);
        pthread_mutex_lock(&mutexA);
        
        pthread_mutex_unlock(&mutexB);

        pthread_mutex_unlock(&mutexA);
    }
    return NULL;
}

int main(){
    pthread_t tid[2];
    if(pthread_create(&tid[0],NULL,&producer,NULL) != 0){
        _exit(1);
    }
    usleep(100);
    if(pthread_create(&tid[1],NULL,&customer,NULL) != 0){
        _exit(1);
    }

    pthread_join(tid[0],NULL);
    return 0;
}
