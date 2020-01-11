#include<stdio.h>
#include<string.h>

#include"yanzheng.h"
#include"shujuji.h"

#define UserName "taxue"
#define QQ "1782285018"
#define BLOG "www.baidu.com"

void Username(void);
void myqq(void);
void myblog(void);

char username[MAX_SIZE],qq[MAX_SIZE],blog[MAX_SIZE];

void yanzheng(void)
{
   printf("输入需要验证的信息，直到完全正确（否则不许进入）!!\n\n");
   Username();
   myqq();
   myblog();
   printf("验证成功，欢迎体验本软件。\n\n");

}

void Username(void)
{
   printf("输入我的网名:");
   while(1)
   {  
	  gets(username);
     if(strcmp(username,UserName)!=0)
      printf("信息错误，请重新输入我网名:\n");
	  else
	  break;
   }
}

void myqq(void)
{  
   printf("请输入我的qq:");
   while(1)
   {  
     gets(qq);
    if(strcmp(qq,QQ)!=0)
      printf("信息错误，请重新输入我qq:\n");
	  else
	  break;
   }
}

void myblog(void)
{
   printf("请输入我的Blog:");
   while(1)
   {  
     gets(blog);
    if(strcmp(blog,BLOG)!=0)
      printf("信息错误，请重新输入我Blog:\n");
	  else
	  break;
   }
}