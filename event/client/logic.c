#include "client.h"

//向服务端发送登陆信息
int send_login(char username_t[],char password_t[])
{
    PACK recv_login_t;
    int login_judge_flag = 0;
    
    //发送包
    send_pack(LOGIN,username_t,"server",password_t);
     
    if(recv(sockfd,&recv_login_t,sizeof(PACK),0) < 0){
        my_err("recv",__LINE__);
    }
    
    //接收服务器返回的登录消息
    login_judge_flag = recv_login_t.data.mes[0] - 48;
    return login_judge_flag;
}
 

//根据输入信息向客户端发送登陆请求
//并根据返回内容，提示用户
int login()
{
    int login_flag = 0;
    char username_t [MAX_CHAR];
    char password_t [MAX_CHAR];
    
    printf("请输入用户名:\n");
    scanf("%s",username_t);
    printf("请输入密码：\n");
    scanf("%s",password_t);
 
    login_flag = send_login(username_t,password_t);
    
    if(login_flag ==  2){
        printf("用户未注册.\n");
        return 0;
    }   
    if(login_flag ==  3 ){
        printf("用户已登录 .\n");
        return 0;
    }  
    if(login_flag ==  0) {
        printf("密码不匹配.\n");
        return 0;
    }
    
    //初始化当前登录用户名
    strcpy(m_my_infor.username,username_t);
    printf("登陆成功\n");
    return 1;
}
 
//向服务端发送注册信息
//成功返回0
int send_registe(char username_t[],char password_t[])
{
    PACK recv_registe_t;
    int send_registe_flag;
    
    send_pack(REGISTER,username_t,"server",password_t);
    
    if(recv(sockfd,&recv_registe_t,sizeof(PACK),0) < 0){
        my_err("recv",__LINE__);
    }
    
    send_registe_flag = recv_registe_t.data.mes[0] - 48;
    return send_registe_flag;
}
 
//根据输入信息向客户端发送注册请求
//并根据返回内容，提示用户
void registe()
{
    int flag = 0;
    flag = REGISTER;
    char username_t[MAX_CHAR];
    char password_t[MAX_CHAR];
    
    printf("注册账号:\n");
    scanf("%s",username_t);
    printf("注册密码:\n");
    scanf("%s",password_t);
    if(send_registe(username_t,password_t))
        printf("成功!\n");
    else 
        printf("姓名重复\n");
}  
 
//向服务端请求更新好友状态
void get_status_mes()
{
    PACK pack_friend_see;
    pack_friend_see.type = FRIEND_SEE;
    
    strcpy(pack_friend_see.data.send_name,m_my_infor.username);
    strcpy(pack_friend_see.data.recv_name,"server");
    memset(pack_friend_see.data.mes,0,sizeof(pack_friend_see.data.mes));
    
    if(send(sockfd,&pack_friend_see,sizeof(PACK),0) < 0){
        my_err("send",__LINE__);
    }
}
 
//根据服务端发送来的包，利用字符串解析，更新当前好友状态
void change_statu(PACK pack_deal_statu_t)
{
    int count = 0;
    m_my_infor.friends_num=pack_deal_statu_t.data.mes[count++];
    
    //更新好友信息
    for(int i=1; i <= m_my_infor.friends_num ;i++)
    {
        for(int j=0;j<SIZE_PASS_NAME;j++)
        {
            if(j == 0)   
                m_my_infor.friends[i].statu = pack_deal_statu_t.data.mes[count+j] - 48;
            else
                m_my_infor.friends[i].name[j-1] = pack_deal_statu_t.data.mes[count+j];
        }
        count += SIZE_PASS_NAME;
    }
    
    //更新群组信息
    m_my_infor.group_num=pack_deal_statu_t.data.mes[count++];
    for(int i=1 ;i <= m_my_infor.group_num ;i++)
    {
        for(int j=0;j<SIZE_PASS_NAME;j++)
        {
            m_my_infor.group[i][j] = pack_deal_statu_t.data.mes[count+j];
        }
        count += SIZE_PASS_NAME;
    }
}
 

//添加好友
void add_friend()
{
    char add_friend_t[MAX_CHAR];
    
    printf("要添加的好友名称:\n");
    scanf("%s",add_friend_t);
    if(strcmp(add_friend_t,m_my_infor.username) == 0)
    {
        printf("不能添加自己!\n");
        return;
    }
    //判断是否已经添加过该好友
    if(judge_same_friend(add_friend_t))
    {
        printf("你已经添加过他!\n");
        return ;
    }
    //printf("m_my_infor.username:%s\n", m_my_infor.username);
    send_pack(FRIEND_ADD,m_my_infor.username,"server",add_friend_t);
    get_status_mes();
}


//添加好友请求
void add_friend_agree(){
    int choice;
    printf("\n----------message----------\n");
    printf("%s 想要添加你为好友！\n",m_pack_recv_friend_add_agree.data.mes);
    do{
        printf("[1]同意\t[2]不同意\n");
        
        fflush(stdin);
        printf("请确认\n");
        scanf("%d",&choice);
        
        if(choice == 2){
            printf("拒绝添加！\n");
            return;
        }
        else if(choice == 1){
            send_pack(AGREE,m_my_infor.username,"server",m_pack_recv_friend_add_agree.data.mes);
            return;
        }
    
    }while(1);
}
 
//删除好友
void del_friend()
{
    char del_friend_t[MAX_CHAR];
    printf("请输入要删除好友名称:\n");
    scanf("%s",del_friend_t);
    
    //判断是否添加过该好友
    if(!judge_same_friend(del_friend_t))
    {
        printf("你没有这个好友!\n");
        return ;
    }
    
    //发送包
    send_pack(FRIEND_DEL,m_my_infor.username,"server",del_friend_t);
    //得到状态信息
    get_status_mes();
}
 
 
//创建群组
void group_create()
{
    char group_name[MAX_CHAR];
    
    printf("请输入要建立的群组名称:\n");
    scanf("%s",group_name);
    send_pack(GROUP_CREATE,m_my_infor.username,"server",group_name);
    
    //等待服务端回复后，跳出循环
    while(!m_flag_group_create);
    
    if(m_flag_group_create == 2) 
        printf("建立成功!\n");
    else if(m_flag_group_create == 1)
        printf("与其他群组重名!\n");
    
    m_flag_group_create = 0;
}
 
 
//加入群组
void group_join()
{
    char group_name[MAX_CHAR];
    printf("输入要加入的群组名称:\n");
    scanf("%s",group_name);
    
    //判断是否已经加入该群
    for(int i=1;i <= m_my_infor.group_num ;i++)
    {
        if(strcmp(m_my_infor.group[i],group_name) == 0)
        {
            printf("你已经加入该群组!\n");
            return ;
        }
    }
 
    send_pack(GROUP_JOIN,m_my_infor.username,"server",group_name);
    
    //等待服务器回复后，跳出循环
    while(!m_flag_group_join);
    
    if(m_flag_group_join == 2) 
        printf("成功!\n");
    else if(m_flag_group_join == 1)
        printf("没有群组叫 %s\n",group_name);
    
    m_flag_group_join = 0;
}
 
//退出群组
void group_qiut()
{
    char group_name[MAX_CHAR];
    
    printf("请输入要退出的群组名称:\n");
    scanf("%s",group_name);
    
    //判断是否添加过该群组
    for(int i=1;i <= m_my_infor.group_num ;i++)
    {
        if(strcmp(m_my_infor.group[i],group_name) == 0)
        {
            send_pack(GROUP_QIUT,m_my_infor.username,"server",group_name);
            printf("退出 %s 成功!\n",group_name);
            return ;
        }
    }
    
    printf("你没加入过这个群组!\n");
}
 
//解散群
void group_del()
{
    char group_name[MAX_CHAR];
    
    printf("请输入要解散的群名称:\n");
    scanf("%s",group_name);
    
    for(int i=1;i <= m_my_infor.group_num ;i++)
    {
        if(strcmp(m_my_infor.group[i],group_name) == 0)
        {
            send_pack(GROUP_DEL,m_my_infor.username,"server",group_name);
            
            //等待服务端回复
            while(!m_flag_group_del);
            //printf("m_flag_group_del=%d\n", m_flag_group_del);
            
            if(m_flag_group_del == 2) 
                printf("解散成功!\n");
            else if(m_flag_group_del == 1)
                printf("你不是 %s 的群主！无法解散\n",group_name);
           
            return ;
        }
    }
    
    printf("你没有在这个群组中!\n");
}
 
 
/*************************************************/
 
//私聊
void send_mes_to_one()
{
    pthread_t pid;
    int id;
    char mes_recv_name[MAX_CHAR];
    
    //打印好友列表
    friends_see();
 
    printf("你想私聊的对象：\n");
    scanf("%s",mes_recv_name);
    
    if (!(id=judge_same_friend(mes_recv_name)))
    {
        printf("你没有添加这个好友 !%s\n",mes_recv_name);
        return ;
    }
    
    printf("****************************消息*********************************\n");
    
    //打印消息标志
    m_flag_print_mes = 1;
    
    //消息数目
    m_my_infor.friends[id].mes_num = 0;
    
    //开启线程显示信息
    pthread_create(&pid,NULL,show_mes,(void *)mes_recv_name);
    
    //发送消息
    send_mes(mes_recv_name,CHAT_ONE);
}
 
//群聊
void send_mes_to_group()
{
    pthread_t pid;
    char mes_recv_group_name[MAX_CHAR];
    group_see();
    printf("请输入群聊名称\n");
    scanf("%s",mes_recv_group_name);
    if (!judge_same_group(mes_recv_group_name))
    {
        printf("你没有加入这个群聊 !%s\n",mes_recv_group_name);
        return ;
    }
 
    m_flag_print_mes = 1;
    printf("****************************私聊*********************************\n");
    
    //开启线程显示信息
    pthread_create(&pid,NULL,show_mes,(void *)mes_recv_group_name);
    
    //发送消息
    send_mes(mes_recv_group_name,CHAT_MANY);

}
 
 
//接收用户输入并发送信息到客户端
void send_mes(char mes_recv_name[],int type)
{
    /* PACK pack_send_mes; */
    char mes[MAX_CHAR];
    time_t timep;
    getchar();
    printf("****************************消息*********************************\n");
    while(1)
    {   
        time(&timep);
        memset(mes,0,sizeof(mes));
        fflush(stdout);
        //if(type == CHAT_ONE)
            // printf("%s->",m_my_infor.username);
        fgets(mes,MAX_CHAR,stdin);
        while(mes[0] == 10)
        {
            fflush(stdout);
            fgets(mes,MAX_CHAR,stdin);
        }
 
        //当用户输入quit时退出
        if(strcmp(mes,"quit\n") == 0)
            break;
 
        //输入的的同时，输出信息
        show_mes_smart(m_my_infor.username ,mes);
        
        //printf("\t%s\n%s\n", m_my_infor.username,ctime(&timep),mes);
        //发送给客户端
        send_pack(type,m_my_infor.username,mes_recv_name,mes);
    }
    m_flag_print_mes = EXIT;
}
 
//在聊天的同时启动,启动线程读取，存储区域的消息，并显示出来
void *show_mes(void *username)
{
    int id;
    char *user_name = (char *)username;
    while(1)
    {
        //如果退出聊天，就不再显示
        if (m_flag_print_mes == EXIT)
            break;
        pthread_mutex_lock(&mutex_local_user); 
        id = 0;
 
        //检索信息
        for(int i = 1 ;i <= m_recv_num_chat; i++)
        {
            if(strcmp(m_pack_recv_chat[i].data.send_name,user_name) == 0)
            {
                id = i;
 
                //输出信息
                print_mes(id);
                m_recv_num_chat--;
                for(int j = id; j <= m_recv_num_chat&&m_recv_num_chat ;j++)
                {
                    m_pack_recv_chat[j]  =  m_pack_recv_chat[j+1];
                }
                break;
            }
        }
        
        pthread_mutex_unlock(&mutex_local_user); 
        usleep(1);    
    }
}
 
//根据寻找到的包把信息输出
void print_mes(int id){
    char group_print_name[MAX_CHAR];

    //确认发送人名称
    memset(group_print_name,0,sizeof(group_print_name));
    
    //判断聊天类型,私聊还是群聊
    if(m_pack_recv_chat[id].type == CHAT_ONE){
        show_mes_smart(m_pack_recv_chat[id].data.send_name,m_pack_recv_chat[id].data.mes);
    }else{    
        //群聊下依次存入发消息的人的名称
        for(int i=0;i<SIZE_PASS_NAME;i++){
            group_print_name[i] = m_pack_recv_chat[id].data.mes[i];
        }
        show_mes_smart(group_print_name,m_pack_recv_chat[id].data.mes+SIZE_PASS_NAME);
    }
}
 
 
 
/*******************************************/
//向服务端请求发送文件，并将文件的大小发送给服务端
 
void send_file()
{
    char  recv_name[MAX_CHAR];
    char  file_path[MAX_CHAR];
    int   file_size_t;
    char  mes_t[MAX_CHAR];
    friends_see();
    printf("请输入收件人:\n");
    scanf("%s",recv_name);
 
    /* int id = judge_same_friend(recv_name);
    if(id == 0)
    {
        printf("你没有这个好友!\n");
        return ;
    } */
    printf("请输入文件名 :\n");
    scanf("%s",file_path); 
    
    //得到文件的大小
    file_size_t = get_file_size(file_path);
    printf("文件大小 :%d\n", file_size_t);
 
    if(file_size_t == 0)
    {
        printf("文件大小为0\n");
        return ;
    }
    //字符串分析
    int digit = 0;
    while(file_size_t != 0)
    {   
        mes_t[digit++] = file_size_t%10;
        file_size_t /= 10;
    }
    mes_t[digit]  = -1;
   
    /*for(int i=0 ;i< SIZE_PASS_NAME ;i++)
    {
        mes_t[NUM_MAX_DIGIT+i] = file_path[i];
    }*/


    int i; 
    for(i = 0;i < SIZE_PASS_NAME && file_path[i] != '\0';i++){
        mes_t[NUM_MAX_DIGIT+i] = file_path[i];
    }
    mes_t[NUM_MAX_DIGIT + i] = '\0';


    //发送请求
    send_pack_memcpy(FILE_SEND_BEGIN,m_my_infor.username,recv_name,mes_t);
} 
 
 
 
//当接收到允许发送的消息时，开启线程发送文件
void *pthread_send_file(void *mes_t)
{
    char *mes = (char *)mes_t;
    int begin_location = 0;
    char file_name[MAX_CHAR];
    printf("\nfunction:pthread_send_file \n");
    
    //解析到服务端已接收文件大小
    for(int i=0 ;i<NUM_MAX_DIGIT ;i++)
    {
        if(mes[i] == -1)  
            break;
        int t1 = 1;
        for(int l=0;l<i;l++)
            t1*=10;
        begin_location += (int)mes[i]*t1;
 
    }
    printf("mes:%s NUM_MAX_DIGIT = %d\n",mes,NUM_MAX_DIGIT);
    strcpy(file_name,mes+NUM_MAX_DIGIT);
    send_file_send(begin_location,file_name);

}
 
 
//从起始位置向服务端发送文件
void send_file_send(int begin_location,char *file_path)
{
    int fd;
    int length;
    int file_size;
    int sum = begin_location;
    char mes[MAX_CHAR*2];
    printf("****************************发送文件*********************************\n");
    printf("\n\n正在发送文件......\n");
    
    /* printf("%s",file_path); */
    //打开文件
    if((fd = open(file_path,O_RDONLY)) == -1)
    {
        printf("%s\n",file_path);
        my_err("open",__LINE__);
        return ;
    }
    file_size=lseek(fd, 0, SEEK_END);
    
    printf("文件大小=%d",file_size);
    //文件内部指针移动
    lseek(fd ,begin_location ,SEEK_SET);
 
    bzero(mes, MAX_CHAR*2); 
 
    // 每读取一段数据，便将其发送给客户端，循环直到文件读完为止 
    while((length = read(fd  ,mes+NUM_MAX_DIGIT ,(MAX_CHAR*2 - NUM_MAX_DIGIT))) > 0) 
    {
        sum += length;
      //  printf("length = %d\n", length);
        int digit = 0;
        while(length != 0)
        {   
            mes[digit++] = length%10;
            length /= 10;
        }
        mes[digit]  = -1;
        printf("正在发送。。。\n");
        send_pack_memcpy(FILE_SEND,m_my_infor.username,file_path,mes);
        
        if(sum == file_size)  
            break;
        bzero(mes, MAX_CHAR*2); 
        usleep(1000);
        fflush(stdout);
    } 
    // 关闭文件 
    close(fd);
    printf("send finished!!\n");
    print_main_menu();
}
 
 
 

//显示文件处理消息，并根据提供选择
int file_mes_box()
{
    char choice_t[100];
    int chioce;
    do
    {
        get_status_mes();
        printf("****************************文件消息盒子*********************************\n");
        for(int i = 1; i <= m_recv_num_file_mes;i++)
        {
            if(m_pack_recv_file_mes[i].type == FILE_SEND_STOP_RP)
                printf("send file %s filed      \n",m_pack_recv_file_mes[i].data.send_name);
            if(m_pack_recv_file_mes[i].type == FILE_RECV_BEGIN)
                printf("%s send file %s to you   \n", m_pack_recv_file_mes[i].data.send_name,m_pack_recv_file_mes[i].data.mes+SIZE_PASS_NAME);
            if(m_pack_recv_file_mes[i].type == FILE_RECV_STOP_RP)
                printf("   recv file %s filed       \n", m_pack_recv_file_mes[i].data.mes+NUM_MAX_DIGIT);
        }
                printf("             0.exit                               \n");
        printf("*************************************************************************\n");
        printf("choice：");
        scanf("%s",choice_t);
        chioce = get_choice(choice_t);
        //进行处理
        if(chioce != -1)   
            deal_file_mes(chioce);
 
    }while(chioce!=0);
    return 0;
}
 








 




//===========================================================================================================================
//对文件信息进行分类处理
void deal_file_mes(int id)
{
    if(m_pack_recv_file_mes[id].type == FILE_SEND_STOP_RP)
    {
        mes_sendfile_fail(id);
    }
    else if(m_pack_recv_file_mes[id].type == FILE_RECV_BEGIN)
    {
        mes_recv_requir(id);
    }else if(m_pack_recv_file_mes[id].type == FILE_RECV_STOP_RP)
    {
        mes_recvfile_fail(id);
    }
}
 
 
//处理文件上传失败，并询问是否重发
//进行断点续传
void mes_sendfile_fail(int id)
{
    char chioce[10];
    //解析已经上传的字节数
    int begin_location = 0;
    for(int i=0 ;i<NUM_MAX_DIGIT ;i++)
    {
        if( m_pack_recv_file_mes[id].data.mes[i] == -1)  
            break;
        printf("%d\n\n",m_pack_recv_file_mes[id].data.mes[i]);
        int t1 = 1;
        for(int l=0;l<i;l++)
            t1*=10;
        begin_location += (int)m_pack_recv_file_mes[id].data.mes[i] * t1;
 
    }
 
 
    //询问是否重传
    int file_size_t = get_file_size(m_pack_recv_file_mes[id].data.send_name);
    printf("the file %s send failed ,have sended %d%%,do you want send again?\n", m_pack_recv_file_mes[id].data.send_name,(int)((double)begin_location/file_size_t*100));
    printf("y/n :");
    scanf("%s",chioce);
    
 
    if(chioce[0] != 'Y' && chioce[0] != 'y')
    {
        file_infor_delete(id);
        return ;
    }
    
    //进行重传
    send_file_send(begin_location,m_pack_recv_file_mes[id].data.send_name);
    file_infor_delete(id);
}
 
//处理下载文件请求，询问是否接收文件
void mes_recv_requir(int id)
{
    pthread_t  pid_recv_file;
    char choice[10];
    int len ;
    int fd;
    char mes_t[MAX_CHAR];
    int file_size = 0;
    char file_name[SIZE_PASS_NAME]; 
    
    PTHREAD_PAR * par_t = (PTHREAD_PAR *)malloc(sizeof(PTHREAD_PAR));
    //解析文件大小
    for(int i=0 ;i<NUM_MAX_DIGIT ;i++)
    {
        if(m_pack_recv_file_mes[id].data.mes[i] == -1)  
            break;
        int t1 = 1;
        for(int l=0;l<i;l++)
            t1*=10;
        file_size += (int)m_pack_recv_file_mes[id].data.mes[i]*t1;
 
    }
     //for(int i=0 ;i<=50;i++)
     //    printf("%d\n", m_pack_recv_file_mes[id].data.mes[i]);
     //printf("%s\n", m_pack_recv_file_mes[id].data.mes+NUM_MAX_DIGIT);
    strcpy(file_name,m_pack_recv_file_mes[id].data.mes+NUM_MAX_DIGIT);
 
    
    printf("是否接收 %s 送来的 %s 大小(%db)？ \n", m_pack_recv_file_mes[id].data.send_name,file_name,file_size);
    printf("[1]接收\t[2]拒绝\n");
    printf("输入你的选择：");
    scanf("%s", choice);
    
    if(choice[0] == '2')
    {
        file_infor_delete(id);
        return ;
    }
 
 
    //建立文件
    if((fd = open(file_name,O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR)) < 0)
    {
        my_err("open",__LINE__);
        return ;
    }
    len = lseek(fd, 0, SEEK_END);
    close(fd);
 
    par_t->a = file_size;
    par_t->b = len;
    
    int digit = 0;
    while(len != 0)
    {   
        mes_t[digit++] = len%10;
        len /= 10;
    }
    mes_t[digit]  = -1;
    //发送同意同意
    send_pack_memcpy(FILE_SEND_BEGIN_RP ,m_my_infor.username ,file_name ,mes_t);
    //开启线程接收文件
    pthread_create(&pid_recv_file,NULL,pthread_recv_file,(void *)par_t);
 
    file_infor_delete(id);
}
 
//处理接收文件中断信息，
//并询问是否继续接收
void mes_recvfile_fail(int id)
{
    pthread_t  pid_recv_file;
    char chioce[10];
    int begin_location_server;
    int file_size;
    char file_name[SIZE_PASS_NAME];
    char mes_t[MAX_CHAR];
    PTHREAD_PAR * par_t = (PTHREAD_PAR *)malloc(sizeof(PTHREAD_PAR));
    //解析已经接收的字节数
    for(int i=0 ;i<NUM_MAX_DIGIT ;i++)
    {
        if(m_pack_recv_file_mes[id].data.mes[i] == -1)  
            break;
        int t1 = 1;
        for(int l=0;l<i;l++)
            t1*=10;
        file_size += (int)m_pack_recv_file_mes[id].data.mes[i]*t1;
 
    }   
 
    strcpy(file_name,m_pack_recv_file_mes[id].data.mes+NUM_MAX_DIGIT);
    
    begin_location_server= get_file_size(file_name);
    
 
    par_t->a = file_size;
    par_t->b = begin_location_server;
    printf("文件 %s 接收失败 ,已经接收了 %d%%,是否选择继续?\n", file_name,(int)((double)begin_location_server/file_size*100));
    
    printf("[1]继续\t[2]放弃\n");
    printf("请输入你的选择：");
    scanf("%s",chioce);
    
    
 
    if(chioce[0] == '2' )
    {
        file_infor_delete(id); 
        return ;
    }
 
 
    int len = begin_location_server;
    int digit = 0;
    while(len != 0)
    {   
        mes_t[digit++] = len%10;
        len /= 10;
    }
    mes_t[digit]  = -1;
 
    //返回同意信息
    send_pack_memcpy(FILE_SEND_BEGIN_RP ,m_my_infor.username ,file_name ,mes_t);
    //开启线程接收文件
    pthread_create(&pid_recv_file,NULL,pthread_recv_file,(void *)par_t);
 
    file_infor_delete(id);
}
//----------------------------------------------------------------------------------------------------------------- 











//接收文件线程，
//从存储接收包的地方检索到信息
//并写入文件
//当文件写入完成，关闭线程
void *pthread_recv_file(void *par_t)
{
    PTHREAD_PAR * pthread_par  = (PTHREAD_PAR * )par_t;
    int file_size              = pthread_par->a ;
    int begin_location_server  = pthread_par->b;
    int sum                    = begin_location_server; 
    while(1)
    {
        pthread_mutex_lock(&mutex_recv_file); 
        int  fd;
        char file_name[MAX_CHAR];
        for(int i=1;i<=m_recv_num_file ;i++)
        {
            
            int  len = 0;
            for(int j=0 ;j<NUM_MAX_DIGIT ;j++)
            {
                if(m_pack_recv_file[i].data.mes[j] == -1)  
                    break;
                int t1 = 1;
                for(int l=0;l<j;l++)
                    t1*=10;
                len += (int)m_pack_recv_file[i].data.mes[j]*t1;
 
            }
 
            strcpy(file_name,m_pack_recv_file[i].data.send_name);
            //you can creat this file when you get the file_send_begin
            if((fd = open(file_name,O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR)) < 0)
            {
                my_err("open",__LINE__);
                return NULL;
            }
 
            if(write(fd,m_pack_recv_file[i].data.mes + NUM_MAX_DIGIT,len) < 0)
                my_err("write",__LINE__);
            // 关闭文件 
            close(fd);
            sum += len;
            m_recv_num_file = 0;
            //文件接收完成，输出提示信息，跳出线程
            if(sum >= file_size)  
            {
                send_pack(FILE_FINI_RP,m_my_infor.username,"server",file_name);
                printf("接收完成\n");
                print_main_menu();
                return NULL;  
            }
        }
 
        pthread_mutex_unlock(&mutex_recv_file);
        usleep(10);
    }   
}
 
 
 
 
 
 
 
//显示历史信息
//向服务端发送请求消息
int mes_record()
{
    char username[MAX_CHAR];
    printf("请输入好友昵称:\n");
    scanf("%s",username);
    //printf("the recording :\n");
    send_pack(MES_RECORD,m_my_infor.username,"server",username);
    printf("****************************聊天记录*********************************\n");
    while(!m_flag_print_recorde) ;
    printf("显示完毕\n");
    m_flag_print_recorde = 0;
    return 0;
}
 
 
 
//输出历史消息
void print_mes_record(PACK* pack_t)
{
    if(strcmp(pack_t->data.send_name , "server") == 0)
    {
        if(strcmp(pack_t->data.mes,m_my_infor.username) == 0)
        {    
            printf("%s\t\n",pack_t->data.mes);
            printf("%s\n", pack_t->data.mes+SIZE_PASS_NAME);
        }
        else
        {
            printf("%s\t\n",pack_t->data.mes);
            printf("%s\n", pack_t->data.mes+SIZE_PASS_NAME);
        }
        
    }
    else 
        m_flag_print_recorde = 1;    
    free(pack_t);
}
