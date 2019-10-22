#include <cstdio>
#include<iostream>
using namespace std;
 
//n个人围成一个圈，数到第m个人让其出列，最后一个人获胜。 
void Josephus(int n,int m) 
{
	int i,j,k;
	int *next = (int *)malloc(n*sizeof(int));
	//构造静态链表 
	for(i=0;i<n-1;++i){
		/* next[i] = i+1; */
        cin >> next[i];
	} 
	next[n-1] = 0;
	k=n-1;
	//出列
	for(i=1;i<n;++i){
		//找到出列人的前驱 
		for(j=1;j<m;++j) k=next[k];
		//正常序号为数组下标加一		
		cout<<"第"<<i<<"个出列的人的编号是"<<next[k]+1<<endl;
		//数到m的人出列，删除该元素 
		next[k] = next[next[k]]; 
	} 
	cout<<"The winner is "<<next[k]+1<<"\n";
}
int main(){
	Josephus(7,20);
	return 0;
}
