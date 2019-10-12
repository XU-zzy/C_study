#include<stdio.h>
#include<string.h>
#include"s_gets.h"
int main(){
	char a[101],z[101];
	int top,i,len,mid,next;

	printf("请输入字符:\n");
	//fgets(a,100,stdin); fegts输入会在最后有一个回车符，所以真实长度应该-1 
	s_gets(a,100);
    len = strlen(a);
	mid = len/2 - 1;		//求字符串中点
	top = 0;
    //printf("%s %d\n",a,len);
	for(i = 0;i <= mid;i++)
		z[++top] = a[i];

	if(len%2 == 0)		//判断字符串是奇数还是偶数，并找出需要进行字符匹配的起始下标
		next = mid + 1;
	else
		next = mid + 2;

	for(i = next;i < len;i++){//开始匹配
		if(a[i] != z[top])
			break;
		top--;
	}
	if(top == 0)
		printf("YES!");
	else
		printf("NO!");
	return 0;
}
