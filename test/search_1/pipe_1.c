#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
//往管道里写
void write_to_pipe(int fd){
    char *message = "hello pipe!\n";
    write(fd,message,strlen(message)+1);
}
//从管道读
void read_from_pipe(int fd){
    char message[100];
    read(fd,message,100);
    printf("read from pipe %s\n",message);
}
int main(){
    int fd[2];  //定义文件描述符
    pid_t pid;  //进程id
    int stat_val;   //返回值;
    if(pipe(fd)){    //创建管道
        printf("Creat pipe falied!\n");
        exit(1);
    }
    pid = fork();   //创建子进程
    switch(pid){
        case -1:
            printf("fork error!\n");
            exit(1);
        case 0:
            close(fd[1]);   //关闭写管道
            read_from_pipe(fd[0]);
            exit(0);
        default:
            close(fd[0]);   //关闭读端
            write_to_pipe(fd[1]);
            wait(&stat_val);
            /* printf("stat_val  %d\n",stat_val); */
            exit(0);
    }
    /* printf("stat_val  %d\n",stat_val); */
    return 0;
}
