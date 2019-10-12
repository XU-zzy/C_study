//从小到大排序
#include<stdio.h>
#include<string.h>
#define N 1000
int a[N];
void quicksort(int left,int right){
        int i,j,t,temp;
        if (left >right)        //从左和从右出发的标记交叉了
            return;
        temp = a[left];         //保存获得基准数，以备后面交换
        i = left;
        j = right;

        while(i < j){           
                while(a[j] >= temp && i < j)    j--;    //寻找右侧比基准数小的数
                while(a[i] <= temp && i < j)    i++;    //寻找左侧比基准数大的数
                //交换数字 
                if(i < j){
                        t = a[i];
                        a[i] = a[j];
                        a[j] = t;
                }
        }
                a[left] = a[i]; //将 i 位置与基准数调换位置
                a[i] = temp;    //将基准数放在i的位置，此时左边的数都比a[i]小，右边的数都比a[i]大
                
                //将数组一分为二，继续进行排序
                quicksort(left,i-1);
                quicksort(i+1,right);
                return;
}

int main(){
	int i,j,temp,num,len,pos;
	int a[N];
	
	printf("请输入要排序数字的总数：\n");
	scanf("%d",&num);
	printf("请输入要排序的数据：\n");
	for(i=0;i<num;i++){
		scanf("%d",&a[i]);
	}
	
	
	//快排
	quicksort(0,num-1);



	//冒泡优化
    /*  i=num-1;  //初始时，长度-1
	while(i){
		pos=0;  //每趟开始，无记录交换
		for(j=0;j<i;j++){
			if (a[j]>a[j+1]){
				pos=j; //记录交换位置
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		i=pos;  //为下一趟排序作准备
	}   */

	//鸡尾酒排序（双冒泡排序）
	/*
	int left =0,right=num-1;
	while(left<right){
		for (i=left;i<right;i++){
			if(a[i]>a[i+1]){     // 找到最小的放在左侧
				temp = a[i];
				a[i] = a[i+1] ;
				a[i+1] = temp;
			}
		}
		right--;
		for(int j=right;j>left;j--){//找到当前排序元素里最小的那个，放在左侧
			if(a[j-1]>a[j]){
				temp = a[j];
				a[j] = a[j-1] ;
				a[j-1] = temp;
			}
		}
 
		left++;		
 
	}*/
	for(i=0;i<num;i++){
		printf("%d ",a[i]);
	}
}
