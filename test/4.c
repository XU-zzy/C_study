typedef struct{
   int value;
   struct process *L;
}semaphore
void wait(semaphore S){
   S.value--;
   if(S.value<0){
       block(S.L);
   }
}
void signal(semaphore S){
   S.value++;
   if(S.value<=0){
       wakeup(S.L);
   }
}
