#include<iostream>
using namespace std;
int main()
{
 string str="hello";
 string s="Hahah";
 const char *s_t = "aaaaa";
 
 str.insert(0,s_t);//在原串下标为1的字符e前插入字符串s
 cout<<str<<endl;

 string str1="hello";
 char c='w';
 str1.insert(4,5,c);//在原串下标为4的字符o前插入5个字符c
 cout<<str1<<endl;

 string str2="hello";
 string s2="weakhaha";
 str2.insert(0,s2,1,3);//将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符h前
 cout<<str2<<endl;

 return 0;
}
