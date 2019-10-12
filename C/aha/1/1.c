#include <stdio.h>
int a[10000];
void InsertSort(int num) {
    int temp = 0;
    for (int i = 1; i < num; i++) {
        int j = i - 1;
        if (a[i] < a[j]) {  
            temp = a[i];    //取出a[i]
            a[i] = a[j];    //a[j]后移
            //a[i]前大于 temp 的部分后移
            //遇到小于 temp 的停止
            while (temp < a[j-1]) {
                a[j] = a[j-1];
                j--;
            }
            //插入 temp
            a[j] = temp;
        }
    }
}
int main()
{
    int i,j,temp,num,len,pos;
	
	printf("请输入要排序数字的总数：\n");
	scanf("%d",&num);
	printf("请输入要排序的数据：\n");
	for(i=0;i<num;i++){
		scanf("%d",&a[i]);
	}	
	//快排
	//quicksort(0,num-1);
    //优化后的冒泡
    //Bubblesort(num);
    //鸡尾酒排序（双冒泡排序）
    //Bubblesort_2(num);
    //直接插入排序
    InsertSort(num);
    //希尔排序
    //shellsort()
    for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
}


