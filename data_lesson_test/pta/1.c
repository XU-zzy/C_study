#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;
void InitList(SqList &L);/*函数的实现此处不再显示*/
int SqInsert(SqList &L,ElemType e);
int main()
{
	SqList L;
	InitList(L);
	ElemType e;
	scanf("%d",&e);
	int result=SqInsert(L,e);
	if(result==0){
		printf("Insertion Error.The storage space is full!");	
	}else if(result==1){
		printf("Insertion Success.The elements of the SequenceList L are:");	
		for(int j=0;j<L.length;j++){
			printf(" %d",L.elem[j]);
		}
	}
	return 0;
}

int SqInsert(SqList &L,ElemType e){
    
    if(L.length == 100){
        return 0;
    }
    
    if(L.elem[0] < e){
        for(int i = L.length-1;i >= 0;i--){
            L.elem[i+1] = L.elem[i];
        }
        L.elem[0] = e;
        return 1;
    }
    
    for(int i = L.length-1;i >= 0;i--){
        if(L.elem[i] > e){
            L.elem[i+1] = e;
            L.length++;
            return 1;
        }
        L.elem[i+1] = L.elem[i];
    }
    return 0;
}



