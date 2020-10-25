//哲学家就餐死锁
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#define N 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


static int chopsticks[N];

void* philosopher(void *p){
    int chop = (int)p;
    while(1){
        printf("philosopher %d is thinking......\n",chop);
        pthread_mutex_lock(&mutex);

        chopsticks[chop] -= 1;
   
        pthread_mutex_lock(&mutex);

        chopsticks[(chop+1)%N] -= 1;
        
        printf("philosopher %d is eating......\n",chop);

        for(int i = 0;i < N;i++){
            printf("chopsticks[%d] =  %d ",i,chopsticks[i]);
        }
        printf("\n");


        /* pthread_mutex_unlock(&mutex); */
    
        chopsticks[chop] += 1;
        chopsticks[(chop+1)%N] += 1;
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t tids[N];
    
    for(int i = 0; i < N;i++){
        chopsticks[i] = 1;
        /* printf("%d\n",chopsticks[i]); */
    }
    /* getchar(); */

    for(int i = 0;i < N;i++){
        if(pthread_create(&tids[i],NULL,philosopher,(void*)i) != 0){
            _exit(1);
        }
        usleep(100);
    }
    pthread_join(tids[0],NULL);
    return 0;
}
