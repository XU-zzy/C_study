#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

//朴素匹配
int pusu_search(int len_s,const char *S,int len_t,const char *T){
    
    int i = 0,j = 0;
    while(i < len_s && j < len_t){  //相同
        /* printf("i = %d\n",i); */
        if(S[i] == T[j]){
            i++;
            j++;
        }else{  //不相同
            //与主串开始匹配的位置 + 1
            i = i - j + 1;
            //子串位置设置为 0 重新开始匹配
            j = 0;
        }

    }

    //匹配成功
    if(j == len_t){
        //返回位置
        return i - j;
    }
    //不能匹配
    return -1;
}

//打印数组函数
void print_num(const int a[],int n){
    for(int i = 0;i < n;i++){
        printf("%d =%d\n",i,a[i]);
    }
    return;
}

//计算next数组
void get_next(int *next,const char *T,int len_t){
    //先初始化为-1
    next[0] = -1;
    //后缀单个字符数组下标
    int i = 0;
    //前缀单个字符数组下标
    int j = -1;
    
    while(i < len_t){
        if(j == -1 || T[i] == T[j]){    //相同，继续匹配
            //同时后移
            i++;
            j++;
            //赋值
            next[i] = j;
        }else{  //不同，j回溯
        /**代码下面解释中的第二个原因语句位置**/
            j = next[j];
        /********************************/
        }
    }
    
    //打印查看next
    /* print_num(next,len_t); */
    return;
}

//计算nextval数组
void get_nextval(int *nextval,const char *T,int len_t){
    nextval[0] = -1;
    int i = 0;
    int j = -1;

    while(i < len_t){
        if(j == -1 || T[i] == T[j]){
            i++;
            j++;
            /* ***********************这里不同************************** */
            if(T[i] != T[j]){
                nextval[i] = j;
            }else{
                nextval[i] = nextval[j];
            }
            /* ******************************************************* */
        }else{
            j = nextval[j];
        }
    }

    //打印查看nextval数组
    print_num(nextval,len_t);
    /* getchar(); */
    return;
}


//KMP算法
int kmp_search(int len_s,const char *S,int len_t,const char *T){
    int next[MAX_SIZE];
    //计算对应的数组
    //未优化
    get_next(next,T,len_t);
    //优化后
    /* get_nextval(next,T,len_t); */

    int i = 0,j = 0;
    while(i < len_s && j < len_t){
        /* printf("i = %d,j = %d\n",i,j); */
        if(j == -1 || S[i] == T[j]){    //匹配成功
            i++;
            j++;
        }else{  //匹配失败，进行跳转
            j = next[j];
        }
    }
    
    //匹配成功
    if(j == len_t){
        return i - j; 
    }
    //不能匹配
    return -1;
}

int main()
{
    //主串
    char S[MAX_SIZE];
    //模式串
    char T[MAX_SIZE];
    
    printf("请输入主串:\n");
    fgets(S,MAX_SIZE,stdin);
    printf("请输入模式串:\n");
    fgets(T,MAX_SIZE,stdin);

    int len_s = strlen(S) - 1;
    int len_t = strlen(T) - 1;

    int id = -1;

    //朴素配对法
    //id = pusu_search(len_s,S,len_t,T);
    
    //KMP
    id = kmp_search(len_s,S,len_t,T);

    printf("位置:%d\n",id);
    return 0;
}

