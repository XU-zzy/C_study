#include<linux/init.h>
#include<linux/kernel.h>
#include <linux/module.h>
#include<linux/list.h>
#include <linux/slab.h>
/*
struct stduent_message{
    int num;
    char name[100];
    struct list_head list;
};*/

struct student
{
   char name[100];
   int num;
   struct list_head list;
};

//以上是定义包含有的struct list_head 结构的数据结构

 

struct student *pstudent;//定义一个结构数组，用来存放数据，注意这里pstudent是数组指针，数组的大小由后面的kmalloc来分配！

 

struct student *tmp_student;//遍历时临时用来存放指向pstudent[i]的指针

struct list_head student_list;//定义链表头（是一个节点）

struct list_head *pos;//指向头结点的一个指针，会在list_for_each中说明

 

int mylist_init(void)
{
   int i = 0;
   INIT_LIST_HEAD(&student_list);//初始化链表头，注意参数是一个指针，用了&符号

   pstudent = kmalloc(sizeof(struct student)*5,GFP_KERNEL);//为结构体数组分配空间，共有5个数组成员
   memset(pstudent,0,sizeof(struct student)*5);//初始化结构体数组
   for(i=0;i<5;i++)//建立链表
   {
      sprintf(pstudent[i].name,"Student%d",i+1);//初始化并显示学生姓名
      pstudent[i].num = i+1; //初始化学生号码
      list_add( &(pstudent[i].list), &student_list);//将pstudent[i].list节点插入到student_list链表中，注意这里是从头结点处插入的，最后顺序为   5、4、3、2、1
   }
list_for_each(pos,&student_list)//遍历链表，此函数指明pos是一个指向节点头的指针，前面已经定义了它的类型。遍历函数相当于一个for循环，{ }内为循环操作，没循环一次pos=&student_list+1！
{
   tmp_student = list_entry(pos,struct student,list);//list_entry（提取数据结构）指针pos指向结构体struct student中的成员list，返回值为指向list所在的结构体的指针（起始地址）
   printk("<0>student %d name: %s\n",tmp_student->num,tmp_student->name);
}//输出此结构体（结构数组其中的一个成员）的数据信息
   return 0;
}
/*
static int __list_init(void){




    printk("hello world \n");
    return 0;
}
*/
static void __lkm_exit(void){
    printk("Goodbye\n");
}


module_init(mylist_init);

/* module_init(__list_init); */
module_exit(__lkm_exit);

MODULE_LICENSE("GPL");
