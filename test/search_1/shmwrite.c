#include"shmdata.h"
int main(){
    int running = 1;
    void *shm = NULL;
    struct shared_use_st *shared = NULL;
    char buffer[BUFSIZ + 1];    //用于保存输入的文本
    int shmid;
    
    //创建共享内存
    //第一个参数（非0整数），为共享内存段命名，
    //函数成功时返回一个与key相关的共享内存标识符（非负整数）,用于后序共享内存函数，
    //失败返回-1
    //第二个参数指定共享内存容量
    //第三个参数shmflg，权限标志，作用与open的mode参数一样
    //如果要想在key标识的共享内存不存在时，创建它的话，可以与IPC_CREAT做或操作。
    //共享内存的权限标志与文件的读写权限一样，
    //举例来说，
    //0644,它表示允许一个进程创建的共享内存被内存创建者所拥有的进程向共享内存读取和写入数据，
    //同时其他用户创建的进程只能读取共享内存
    shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
    if(shmid == -1){

        fprintf(stderr,"shmget failed\n");
        exit(EXIT_FAILURE);
    }

    
    //第二个参数指定共享内存连接到当前进程中的地址位置，通常为空，表示让系统来选择共享内存的地址。
    //第三个参数是一组标志位，通常为0。
    //调用成功时返回一个指向共享内存第一个字节的指针，如果调用失败返回-1.
    shm = shmat(shmid,(void*)0,0);
    if(shm == (void*)-1){
        fprintf(stderr,"shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n",(int)shm);

    //将申请到的共享内存强制转化为我们自己定义的结构体
    shared = (struct shared_use_st*)shm;
    while(running){ //向共享内存中写数据
        //数据还没有被读取，则等待数据被读取，不能向共享内存中写入文本
        while(shared->written == 1){
            sleep(1);
            printf("Waiting...\n");
        }

        printf("Enter some text:");
        fgets(buffer,BUFSIZ,stdin);
        strncpy(shared->text,buffer,TEXT_SZ);

        shared->written = 1;
        if(strncmp(buffer,"end",3) == 0){
            running = 0;
        }
    }

    //把共享内存从当前进程中分离
    if(shmdt(shm) == -1){
        fprintf(stderr,"shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    sleep(2);
    exit(EXIT_FAILURE);
}
