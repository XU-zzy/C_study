#include "client.h"

//登陆菜单
int login_menu()
{
    char choice_t[100];
    int chioce;
    do
    {
        printf("\n*******************************\n");
        printf("        [1].登录            \n");
        printf("        [2].注册            \n");
        printf("        [0].退出                \n");
        printf("*******************************\n");
        printf("你的选择：");
        scanf("%s",choice_t);
        chioce = get_choice(choice_t);
        switch(chioce)
        {  
            case 1:
                if(login() == 1)
                    return 1;
                break;
            case 2:
                registe();
                break;
            default:
                break;
        }
    }while(chioce!=0);
    return 0;
}
 
//显示聊天信息
void show_mes_smart(char *name  ,char *mes)
{
    time_t timep;
    int number = 6;
    char time1[100];
    int len ; 
    time (&timep);
    
    strcpy(time1,ctime(&timep));
    
    len = strlen(time1);
    time1[len-5] = '\0'; 
 
    if(m_print_mes_num == number)  
    {
        for(int i=1;i<=5 ;i++)
            m_print_mes[i] = m_print_mes[i+1];
        strcpy(m_print_mes[number].name,name);
       // strcpy(m_print_mes[number].time,time);
        strcpy(m_print_mes[number].mes,mes);
    }
    else{
         strcpy(m_print_mes[++m_print_mes_num].name,name);
         //strcpy(m_print_mes[m_print_mes_num].time,time);
         strcpy(m_print_mes[m_print_mes_num].mes,mes);
    }
 
 
    /*for(int i=1;i<=m_print_mes_num;i++)*/
    /* { */
        int i = m_print_mes_num;
        if(strcmp(m_print_mes[i].name,m_my_infor.username) == 0)
        {
            printf("%s\t%s\n",m_print_mes[i].name,time1+10);
            printf("%s\n", m_print_mes[i].mes);
        }
        else
        {
            printf("%s\t%s\n",m_print_mes[i].name,time1+10);
            printf("%s\n", m_print_mes[i].mes);
        }
 
    /* } */
    /*for(int i=1;i<=6- m_print_mes_num ;i++)
    {
        printf("\n");
        printf("\n\n");
 
    }*/
    fflush(stdout);
}
 
 
 
 
//好友列表查看
void friends_see()
{
    pthread_mutex_lock(&mutex_local_user);
    printf("***********好友列表*************\n");
    for(int i=1 ;i<=m_my_infor.friends_num ;i++)
    {
        switch(m_my_infor.friends[i].statu)
        {
           case ONLINE:
                printf("  ID[%d]:       %s [ONLINE] ", i,m_my_infor.friends[i].name);
                //好友消息
                if(m_my_infor.friends[i].mes_num)
                    printf("%d messages\n", m_my_infor.friends[i].mes_num);
                else 
                    printf("\n");
                break;
           case DOWNLINE:
                printf("\n  ID[%d]:     %s [DOWNLINE] ", i,m_my_infor.friends[i].name);
                if(m_my_infor.friends[i].mes_num)
                    printf("%d messages\n", m_my_infor.friends[i].mes_num);
                else 
                    printf("\n");
                break;
        }
    }
    printf("\n\n");
    printf("********************************\n");
    pthread_mutex_unlock(&mutex_local_user);  
}
 
 
 

//群组信息查看
void group_see()
{
    pthread_mutex_lock(&mutex_local_user); 
    printf("***********群组列表*************  \n");
    for(int i=1 ;i<=m_my_infor.group_num ;i++)
    {
        printf("  ID[%d]:       %s", i,m_my_infor.group[i]);
    }
    printf("\n\n");
    printf("*************************************** \n");
    pthread_mutex_unlock(&mutex_local_user);  
}
 
 
 
//主菜单 
void print_main_menu()
{
    printf("\n********************************* \n");
    printf("        [1]显示好友       \n");
    printf("        [2]添加好友       \n");
    printf("        [3]删除好友       \n");
    printf("        [4]显示群组         \n");
    printf("        [5]创建群组         \n");
    printf("        [6]加入群组         \n");
    printf("        [7]退出群组         \n");
    printf("        [8]解散群组         \n");
    printf("        [9]私聊        \n");
    printf("        [10]群聊      \n");
    printf("        [11]发文件          \n");
    printf("        [12]文件消息盒子 %d \n",m_recv_num_file_mes);
    //printf("\t\t        13.mes recording       \n");
    printf("        [0]退出                 \n");
    printf("*********************************\n");
    printf("选择：");
}
