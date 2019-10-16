// GeneralList.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct GLNode{
	int tag;        //标识域
	union{
		char atom;
		struct GLNode *head;
	};
	struct GLNode *next;
};
 
typedef struct GLNode GList;
 
//求取广义表的子串Subs
void Getsubs(char str[], char hstr[]){
	int i=0;
	int j=0;
	int k=0;     //用来记录没有匹配的左括号数
	int r=0; 
	char s[100];
	while(str[i]&&(str[i]!=','||k)){
		if(str[i]=='(')
			k++;
		else if(str[i]==')')
			k--;
 
		if(str[i]!=','||(str[i]==','&&k)){
			hstr[j]=str[i];
			i++;
			j++;
		}
	}
	hstr[j]='\0';
	if(str[i]==',')
		i++;
	while(str[i]){
		s[r]=str[i];
		r++;
		i++;
	}
	s[r]='\0';
	strcpy(str,s);
 
}
 
//创建广义表
GList *GListCreate(char str[]){
  GList *G;
  char subs[100];
  char hstr[100];
  GList *q;
  int len=strlen(str);
  if(len==0||!strcmp(str,"()"))
	  G=NULL;
  else if(len==1){  //原子结点的情况
		  G=(GList *)malloc(sizeof(GList));
		  if(!G){
			  printf("申请空间失败！");
			  exit(0);
		  }
		  G->tag = 0;
		  G->atom = *str;
		  G->next = NULL;
  }else{
	 GList *p;
     G=(GList *)malloc(sizeof(GList));
	 if(!G){
		printf("申请空间失败！");
		exit(0);
	  }
	  G->tag = 1;
	  p=G;
	  str++;
	  strncpy(subs,str,len-2);       //去掉最外面的()
	  subs[len-2]='\0';
	  while(len>0){
		GList *r;
		Getsubs(subs,hstr);         //将subs分开为表头hstr和表尾subs
		r=GListCreate(hstr);        //生成表头的广义表
		p->head=r;
		q=p;
		len=strlen(subs);
		if(len>0){
           p=(GList *)malloc(sizeof(GList));
		   if(!G){
			  printf("申请空间失败！");
			  exit(0);
		    }
		    p->tag = 1;
			q->next=p;
		 }
	}
	q->next=NULL;
  }
  return G;
}
 
//打印广义表
void GLisnextprint(GList *G){
   GList *q,*p;
   printf("(");
   while(G){
	   p=G->head;
	   q=G->next;
	   if(p&&q&&!p->tag){       //p为原子结点，并且有后续结点
         printf("%c,",p->atom);
		 p=q->head;
	     q=q->next;
	   }
	   if(p&&!p->tag){           //p为原子结点，并且没有后续结点
         printf("%c",p->atom);
		 break;
	   }
	   else{
		   if(!p)
              printf("()");          //p为空表
		   else
			  GLisnextprint(p);
		   if(q)
              printf(",");          //还存在着后续的结点
		   G=q;
	   }
   }
   printf(")"); 
}
 
int main(){
	int n;
	char *s;
	GList *G;
	printf("请输入广义表的字符数：\n");
	scanf("%d",&n);
    printf("请输入广义表：\n");
	s=(char *)malloc(n*sizeof(char));
	scanf("%s",s);
	G=GListCreate(s);
    printf("所输入的广义表为：\n");
	GLisnextprint(G);
	printf("\n");
	return 0;
}
