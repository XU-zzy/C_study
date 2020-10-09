#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>                                                                                                                                         
#include<errno.h>
#include<unistd.h>
#include<semaphore.h>
sem_t plate,apple,orange;
void *father(void *p){
    while(1){
        sem_wait(&plate);
        printf("father apple:%d,orange%d");
        sleep(1);
        sem_post(&apple);
    }
    return NULL;
}
void *mother(void *p){
    while(1){
        sem_wait(&plate);
        printf("2\n");
        sleep(1);
        sem_post(&orange);
    }
    return NULL;
}
void *daughter(void *p){
    while(1){
        sem_wait(&apple);
        printf("3\n");
        sleep(1);
        sem_post(&plate);
    }
    return NULL;
}
void *son(void *p){
    while(1){
        sem_wait(&orange);
        printf("4\n");
        sleep(1);
        sem_post(&plate);
    }
    return NULL;
}
int main(void){
    sem_init(&plate,0,1);
    sem_init(&apple,0,1);
    sem_init(&orange,0,0);
    pthread_t tid[4];
    pthread_create(&tid[0],NULL,father,NULL);
    pthread_create(&tid[1],NULL,mother,NULL); 
    pthread_create(&tid[2],NULL,son,NULL); 
    pthread_create(&tid[3],NULL,daughter,NULL); 
    pthread_join(tid[0],NULL);
    sem_destroy(&plate);
    sem_destroy(&apple);
    sem_destroy(&orange);
}
