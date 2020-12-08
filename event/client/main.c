 #include <mysql/mysql.h>                                                                                                                                            
  #include <stdio.h>
  #include <pthread.h>
  #include <sys/socket.h>
  #include <sys/epoll.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <signal.h>
  #include <time.h>
  #include <termios.h>  
   
  //定义参数宏
  #define LOGIN                    1
  #define REGISTER                 2
  #define FRIEND_SEE               3
  #define FRIEND_ADD               4
  #define FRIEND_DEL               5
  #define GROUP_SEE                6  
  #define GROUP_CREATE             7
  #define GROUP_JOIN               8
  #define GROUP_QIUT               9
  #define GROUP_DEL                10
  #define CHAT_ONE                 11
  #define CHAT_MANY                12
  #define FILE_SEND_BEGIN          13
  #define FILE_SEND_BEGIN_RP       14
  #define FILE_SEND_STOP_RP        15
  #define FILE_RECV_RE             16
  #define FILE_SEND                17
  #define FILE_RECV_BEGIN          18 
  #define FILE_RECV_BEGIN_RP       19
  #define FILE_RECV_STOP_RP        20
  #define FILE_RECV                21
  #define FILE_FINI_RP             22
  #define MES_RECORD               23
  #define EXIT                     -1
  #define AGREE                    24

  #define SIZE_PASS_NAME   100
  #define MAX_PACK_CONTIAN 100
  #define MAX_CHAR         300
  #define NUM_MAX_DIGIT    10

  #define DOWNLINE   0
  #define ONLINE     1
  #define BUZY       2


/**************************************************/
  //好友信息
  typedef struct  friend_info
  {
      //状态
      int statu;
      //接收到好友的信息数
      int mes_num;
      //好友名字
      char name[MAX_CHAR];
  }FRIEND_INFO;

  //用户信息
  typedef struct user_infor{
      char        username    [MAX_CHAR];
      FRIEND_INFO friends     [MAX_CHAR];
      int         friends_num;
      char        group       [MAX_CHAR][MAX_CHAR];
      int         group_num;
  }USER_INFOR;

  //和服务端保持一致
  //包信息
  typedef struct datas{
      char    send_name[MAX_CHAR];
      char    recv_name[MAX_CHAR];
      int     send_fd;
      int     recv_fd;
      //time_t  time;
      
      //发送所带信息
      char    mes[MAX_CHAR*2];
  }DATA;

  typedef struct package{
      //包的类型
      int type;
      DATA  data;
  }PACK;

  typedef struct pthread_parameter
  {
      int a;
      int b;
  }PTHREAD_PAR;

  //聊天时消息信息
  typedef struct prinit_mes
  {
      char name[MAX_CHAR];
      char time[MAX_CHAR];
      char mes [MAX_CHAR];
  }PRINT_MES;

  typedef struct sockaddr SA;



  USER_INFOR m_my_infor;

  //发送包
  PACK m_pack_send   [MAX_CHAR]; 
  int  m_send_num;

  //接收到的各种包
  PACK m_pack_recv_friend_see   [MAX_PACK_CONTIAN];
  PACK m_pack_recv_chat         [MAX_PACK_CONTIAN];
  PACK m_pack_recv_send_file    [MAX_PACK_CONTIAN];
  PACK m_pack_recv_file_mes     [MAX_PACK_CONTIAN];
  PACK m_pack_recv_file         [MAX_PACK_CONTIAN];
  PACK m_pack_recv_friend_add_agree;

  int m_recv_num_friend_see;
  int m_recv_num_chat;
  int m_recv_num_send_file;
  int m_recv_num_file_mes;
  int m_recv_num_file;
  int m_print_mes_flag;
  
  /****************************************************/
  int m_flag_group_create;
  int m_flag_group_join ;
  int m_flag_group_del  ;
  int m_flag_print_mes;
  int m_flag_print_recorde;

  /****************************************************/
  PRINT_MES m_print_mes[10];
  int m_print_mes_num;

  //定义套接字，IP，端口
  int sockfd;
  /* char *IP = "192.168.1.43"; */
  /* char *IP = "192.168.3.210"; */
  char *IP = "192.168.122.1";
  short PORT = 4057;
  typedef struct sockaddr SA; 

  //定义锁参数
  pthread_mutex_t  mutex_local_user;
  pthread_mutex_t  mutex_recv_file;

  //-------------------------------------------------------
  //函数定义

  //主函数
  void init();
  void *deal_statu(void *arg);
  void *clien_recv_thread(void *arg);
  void init_clien_pthread();
  int main_menu();

  //功能函数
  int send_login(char username_t[],char password_t[]);
  int login();
  int send_registe(char username_t[],char password_t[]);
  void registe();
  void get_status_mes();
  void change_statu(PACK pack_deal_statu_t);
  void add_friend();
  void del_friend();
  void group_create();
  void group_join();
  void group_qiut();
  void group_del();
  void send_mes_to_one();
  void send_mes_to_group();
  void send_mes(char mes_recv_name[],int type);
  void *show_mes(void *username);
  void print_mes(int id);
  void send_file();
  void *pthread_send_file(void *mes_t);
  void send_file_send(int begin_location,char *file_path);
  int file_mes_box();
  void deal_file_mes(int id);
  void mes_sendfile_fail(int id);
  void mes_recv_requir(int id);
  void mes_recvfile_fail(int id);
  void *pthread_recv_file(void *par_t);
  int mes_record();
  void print_mes_record(PACK* pack_t);

  //view函数
  int login_menu();
  void show_mes_smart(char *name  ,char *mes);
  void friends_see();
  void group_see();
  void print_main_menu();

  //工具函数
  void my_err(const char * err_string,int line);
  void sig_close(int i);
  int get_file_size(char *file_name);
  void file_infor_delete(int id);
  int judge_same_group(char *group_name);
  int judge_same_friend(char add_friend_t[]);
  int get_choice(char *choice_t);
  void send_pack(int type,char *send_name,char *recv_name,char *mes);
  void send_pack_memcpy(int type,char *send_name,char *recv_name,char *mes);
  void add_friend_agree();

//定义锁参数
extern pthread_mutex_t  mutex_local_user;
extern pthread_mutex_t  mutex_recv_file;

//主函数
int main(int argc, char const *argv[])
  {
      
      //关闭CTRL+C 
      signal(SIGINT,sig_close);                                                                                                                                       
      //启动并连接服务器
      init();
      
      //判断是否登陆成功
      if(login_menu() == 0)
          return 0;   
      
      //开启线程
      init_clien_pthread();
      
      //主菜单
      main_menu();
      return 0;
  }

//创建套接字，并和服务器创建连接
void init()
{
    //创建套接字
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    
    //初始化
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);
    
    //连接
    if(connect(sockfd,(SA*)&addr,sizeof(addr))==-1){
        perror("无法连接到服务器");
        printf("客户端启动失败\n");
        exit(-1);
    }
    printf("客户端启动成功\n");
}
 
 
//根据发来数据包及时更新
//好友状态
void *deal_statu(void *arg)
{
    int i;
    while(1)
    {
        pthread_mutex_lock(&mutex_local_user); 
        for(i=1;i<=m_recv_num_friend_see;i++)
        {
            change_statu(m_pack_recv_friend_see[i]);
        }
        m_recv_num_friend_see = 0;
        pthread_mutex_unlock(&mutex_local_user); 
        usleep(1); 
    }
}
 
 
//一直接收客户端发来的包
//并把包存储到数组当中
void *clien_recv_thread(void *arg)
{
    PACK pack_t;
    pthread_t pid_send_file;
    //始终接收包
    while(1)
    {
        //接收包
        if(recv(sockfd,&pack_t,sizeof(PACK),0) < 0){
            my_err("recv",__LINE__);
        }
        
        //上锁
        pthread_mutex_lock(&mutex_local_user); 
        
        //-------------------------------------------
        //统计好友消息
        for(int i=1 ;i<= m_my_infor.friends_num;i++)
        {
            if(strcmp(m_my_infor.friends[i].name,pack_t.data.send_name) == 0)
            {
                m_my_infor.friends[i].mes_num++;
                break;
            }
        }
        //--------------------------------------------
        
        //对不同的包进行处理
        switch(pack_t.type)
        {
            //添加好友提醒
            case AGREE:
                m_pack_recv_friend_add_agree = pack_t;
                add_friend_agree(); 
                break;
            //查看好友
            case FRIEND_SEE:
                m_pack_recv_friend_see[++m_recv_num_friend_see] = pack_t;
                break;
            //创建群聊
            case GROUP_CREATE:
                m_flag_group_create = pack_t.data.mes[0];
                break;
            //加入群聊
            case GROUP_JOIN:
                m_flag_group_join   = pack_t.data.mes[0];
                break;
            //解散群聊
            case GROUP_DEL:
                m_flag_group_del    = pack_t.data.mes[0];
                break;
            //私聊
            case CHAT_ONE:
                m_pack_recv_chat[++m_recv_num_chat]  = pack_t;
                break;
            //群聊
            case CHAT_MANY:
                m_pack_recv_chat[++m_recv_num_chat]  = pack_t;
                break;
            

            //case SEND_FILE:
              //  m_pack_recv_send_file[++m_recv_num_send_file]   = pack_t;
                //break; 
            case FILE_SEND_BEGIN_RP:
                 pthread_create(&pid_send_file,NULL,pthread_send_file,(void *)pack_t.data.mes);
                break; 
            case FILE_SEND_STOP_RP:
                m_pack_recv_file_mes[++m_recv_num_file_mes]             = pack_t;
                //printf("\n\nm_pack_recv_file_mes[++m_recv_num_file_mes] 1= %s\n\n",m_pack_recv_file_mes[++m_recv_num_file_mes].data.mes); 
                break;
            case FILE_RECV_BEGIN:
                m_pack_recv_file_mes[++m_recv_num_file_mes]             = pack_t;
                /* printf("pack = %s",pack_t.data.mes+NUM_MAX_DIGIT); */
                /* printf("\n\nm_pack_recv_file_mes[++m_recv_num_file_mes] 2= %s\n\n",m_pack_recv_file_mes[++m_recv_num_file_mes].data.mes); */
                break;
           
 
            //接收文件
            case FILE_RECV:
                pthread_mutex_lock(&mutex_recv_file); 
                m_pack_recv_file[++m_recv_num_file]                     = pack_t;                
                //printf("\n\nm_pack_recv_file_mes[++m_recv_num_file_mes] 3= %s\n\n",m_pack_recv_file_mes[++m_recv_num_file_mes].data.mes); 
                pthread_mutex_unlock(&mutex_recv_file);
                break; 
            case FILE_RECV_STOP_RP:
                m_pack_recv_file_mes[++m_recv_num_file_mes]             = pack_t;
                //printf("\n\nm_pack_recv_file_mes[++m_recv_num_file_mes] 4= %s\n\n",m_pack_recv_file_mes[++m_recv_num_file_mes].data.mes); 
                break;
            
            //消息记录
            case MES_RECORD:
                PACK *pack_record = (PACK *)malloc(sizeof(PACK));
                memcpy(pack_record,&pack_t,sizeof(PACK));
                print_mes_record(pack_record);
                break;
        }
        //解锁
        pthread_mutex_unlock(&mutex_local_user); 
        usleep(1); 
    }
}
 
 
//开启线程
void init_clien_pthread()
{
    pthread_t pid_deal_statu,pid_recv,pid_recv_file;
    //收包处理线程
    pthread_create(&pid_deal_statu,NULL,deal_statu,NULL);
    //实时接收包线程
    pthread_create(&pid_recv,NULL,clien_recv_thread,NULL);
} 
 
 
//主菜单
int main_menu()
{
    char choice_t[100];
    int chioce;
    do
    {
        //更新信息
        get_status_mes();
        //printf("pack num_chat:%d\n", m_recv_num_chat);
        //打印主菜单
        print_main_menu();
        scanf("%s",choice_t);
        chioce = get_choice(choice_t);
        switch(chioce)
        {  
            case 1:
                //查看好友
                friends_see();
                break;
            case 2:
                //添加好友
                add_friend();
                break;
            case 3:
                //删除好友
                del_friend();
                break;
            case 4:
                //查看群组
                group_see();
                break;
            case 5:
                //创建群组
                group_create();
                break;
            case 6:
                //加入群组
                group_join();
                break;
            case 7:
                //退出群组
                group_qiut();
                break;
            case 8:
                //解散群组
                group_del();
                break;
            case 9:
                //私聊
                send_mes_to_one();
                break;
            case 10:
                //群聊
                send_mes_to_group();
                break;
            case 11:
                //发送文件
                send_file();
                break;
            case 12:
                //文件消息盒子
                file_mes_box();
                break;
            case 13:
                //消息记录
                mes_record();
            default:
                break;
        }
    }while(chioce!=0);
    return 0;
}
