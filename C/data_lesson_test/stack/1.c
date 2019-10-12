#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char ele;
    struct Node * next;
}Node;

typedef Node * Stack;

Stack MakeStack(void)//新建栈并返回栈顶
{
    Stack S = (Node *)malloc(sizeof(Node));
    S->next = NULL;
    return S;
}

void MakeNUll(Stack S)//置空栈
{
    S->next = NULL;
}

void Pop(Stack S)//将栈顶弹出
{
    Stack temp = S->next;
    S->next = temp->next;
}

void Push(Stack S, char c)//将新节点压入栈
{
    Stack temp = (Node *)malloc(sizeof(Node));
    temp->ele = c;
    temp->next = S->next;
    S->next = temp;
}

Stack FindHead(Stack S)//返回栈顶
{
    Stack temp = S->next;
    return temp;
}

void PrintHead(Stack S)//打印栈顶元素
{
    Stack temp = S->next;
    printf("%c", temp->ele);
}

int main(void)
{
    Stack S = MakeStack();
    int i = 0;
    char str[200];
    printf("Type something.\n");
    fgets(str,200,stdin);

    while(str[i] != '\0')
    {
        if(str[i] == '+' || str[i] == '-')//如果str[i]是加号或减号，则先弹出栈顶直到栈已空或栈顶元素为左括号，再将str[i]压入栈
        {
            if(FindHead(S) == NULL)//若栈已空时，栈顶指针为空，找不到其元素，故须单独讨论
            {
                Push(S, str[i]);
            }
            else
            {
                while(FindHead(S)->ele == '+' || FindHead(S)->ele == '-' || FindHead(S)->ele == '*' || FindHead(S)->ele == '/')
                {
                    PrintHead(S);
                    Pop(S);
                }
                Push(S, str[i]);
            }
        }

        else if(str[i] == '*' || str[i] == '/')//如果str[i]是乘号或除号，则只有栈顶也是乘除号时才需要弹出
        {
            if(FindHead(S) == NULL)
            {
                Push(S, str[i]);
            }
            else
            {
                while(FindHead(S)->ele == '*' || FindHead(S)->ele == '/')
                {
                    PrintHead(S);
                    Pop(S);
                }
                Push(S, str[i]);
            }
        }

        else if(str[i] == '(')//如果str[i]是左括号则直接压入栈
        {
            Push(S, str[i]);
        }

        else if(str[i] == ')')//如果str[i]是右括号，则打印并弹出栈中第一个左括号前的所有操作符，最后将此左括号直接弹出
        {
            while(FindHead(S)->ele != '(')
            {
                PrintHead(S);
                Pop(S);
            }
            Pop(S);
        }

        else//如果str[i]不是操作符则直接打印
        {
            printf("%c", str[i]);
        }

        i++;
    }

    while(FindHead(S) != NULL)//遍历后如果栈不为空，则弹出所有操作符
    {
        PrintHead(S);
        Pop(S);
    }

    return 0;
}
