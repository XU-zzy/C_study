#include <stdio.h>
#include <stdlib.h>
 
typedef char elemType; 
 
/************************************************************************/
/*                      以下是关于广义表操作的4个简单算法               */
/************************************************************************/ 
struct GNode{
    int tag;        /* 标志域：取0表示单元素结点；取1时表示子表结点 */
    union{
        elemType data;
        struct GNode *subList;
    };
    struct GNode *next;        /* 指向后继结点的指针域 */ 
};  
 
   
 
/* 1.求广义表的长度 */
int lenthGList(struct GNode *gl)
{
    if(gl != NULL){
        return 1 + lenthGList(gl->next);    
    }else{
        return 0;
    }    
} 
 
/* 2.求广义表的深度 */
int depthGList(struct GNode *gl)
{
    int max = 0;
    /* 遍历每个结点，求出所以子表的最大深度 */
    while(gl != NULL){
        if(gl->tag == 1){
            /* 递归求出一个子表的深度 */
            int dep = depthGList(gl->subList);
            /* 让max始终为同一个所求子表中深度的最大值 */
            if(dep > max){
                max = dep;
            }
        }
        gl = gl->next;     /* 让gl指向下一个结点 */
    }
    return max + 1;        /* 返回表的深度 */
}
 
/* 3.建立广义表的存储结构 */
void creatGList(struct GNode* *gl)
{
    char ch;/* 读入一个字符，此处可能读入'＃'，'（'，'）'，','或者英文字母 */
    scanf("%c", &ch);
    /* 若输入为＃，则置表头指针为空 */
    if(ch == '#'){
        *gl = NULL;
    }
    /* 若输入左括号则建立由*gl所指向的子表结点并递归构造子表 */
    else if(ch == '('){
        *gl =(struct GNode*)malloc(sizeof(struct GNode));
        (*gl)->tag = 1;
        creatGList(&((*gl)->subList));
    }
    /* 若输入为字符则建立由*gl所指向的单元素结点 */
    else{
        *gl = (struct GNode*)malloc(sizeof(struct GNode));
        (*gl)->tag = 0;
        (*gl)->data = ch;
    }
    /* 此处读入的字符必为逗号或右括号或分号 */
    scanf("%c", &ch);
    /* 若*gl为空，则什么都不做 */
    if(*gl == NULL){
        ;
    }
    /* 若输入为逗号则递归构造后继表 */
    else if(ch == ','){
        creatGList(&((*gl)->next));
    }
    /* 若输入为右括号或分号则置*gl的后继指针域为空 */
    else if((ch == ')') || (ch == ';')){
        (*gl)->next = NULL;
    } 
    return;
}
 
/* 4.打印广义表 */
void printGList(struct GNode *gl)
{
    /* 对于表结点的处理 */
    if(gl->tag == 1){
        /* 存在子表，先输出左括号 */
        printf("(");
        /* 若子表为空，则输出'#'字符 */
        if(gl->subList == NULL){
            printf("#");
        }
        /* 若子表非表，则递归输出子表 */
        else{
            printGList(gl->subList);
        }
        /* 当一个子表输出结束后，再输出右括号 */
        printf(")");
    }
    /* 对单元素结点，则输出该结点的值 */
    else{
        printf("%c", gl->data);
    }
    /* 输出该结点的后继表 */
    if(gl->next != NULL){
        /* 先输出逗号分隔 */
        printf(", ");
        /* 再递归输出后继表 */
        printGList(gl->next);
    }
    return;
}
 
 
int main()
{
    struct GNode *gl;
    printf("输入一个广义表， 以右括号结束 ");
    creatGList(&gl);
    printf("输出广义表：");
    printGList(gl);
    printf("\n");
    printf("广义表的长度：");
    printf("%d \n", lenthGList(gl->subList));
    printf("广义表的深度：");
    printf("%d \n", depthGList(gl->subList));
    return 0;    
}
