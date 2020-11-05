//
// Created by zzy on 2020/11/5.
//

#ifndef HUFFMAN_WORK_H
#define HUFFMAN_WORK_H


#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

//phi.c
#define M 5
sem_t sfork[5];

void *philosopher(void *p);

//pro_con_4.c
#define M_p 8   //生产者和消费者的个数
#define N   10  //缓冲区大小
sem_t space,prod,sin,sout;

int Buffer[N];      //缓冲区
//int in = 0,out = 0; //定义队头队尾

void *producer(void *p);
void *consumer(void *p);

//r_w_2.c
//写者数量
#define M_w   10
//读者最多的数量
#define N_w   20
sem_t sdata,sread;
//int readcount = 0;

void *reader(void *p);
void *writer(void *p);

#endif //HUFFMAN_WORK_H
