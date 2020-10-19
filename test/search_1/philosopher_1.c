#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#define M 5
sem_t sfork[5];

void *philosopher(void *p){
    int id = (int)p;
    while(1){
        //Thinking...
        sem_wait(&sfork[id]);
        sem_wait(&sfork[(id+1)%5]);
        //Eating...
        sem_post(&sfork[id]);
        sem_post(&sfork[(id+1)%5]);
    }
    return NULL;
}

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
