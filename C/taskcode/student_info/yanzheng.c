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
   printf("������Ҫ��֤����Ϣ��ֱ����ȫ��ȷ����������룩!!\n\n");
   Username();
   myqq();
   myblog();
   printf("��֤�ɹ�����ӭ���鱾�����\n\n");

}

void Username(void)
{
   printf("�����ҵ�����:");
   while(1)
   {  
	  gets(username);
     if(strcmp(username,UserName)!=0)
      printf("��Ϣ��������������������:\n");
	  else
	  break;
   }
}

void myqq(void)
{  
   printf("�������ҵ�qq:");
   while(1)
   {  
     gets(qq);
    if(strcmp(qq,QQ)!=0)
      printf("��Ϣ����������������qq:\n");
	  else
	  break;
   }
}

void myblog(void)
{
   printf("�������ҵ�Blog:");
   while(1)
   {  
     gets(blog);
    if(strcmp(blog,BLOG)!=0)
      printf("��Ϣ����������������Blog:\n");
	  else
	  break;
   }
}