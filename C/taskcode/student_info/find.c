#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"shujuji.h"
#include"function.h"
#include"xianshi.h"
struct role *search_name(struct role *h,char name[6])
{
   struct role *p=NULL;
   if(h==NULL)
	   printf("链表为空，没有所需结点！\n");
   else
   {
	   for(p=h;p!=NULL;p=p->next)
	 {
	   if(p->name == name)
       {
	      printf("成功找到结点^_^\n");
		  printf("结点信息如下：\n");
          printf("学号	  姓名	   性别     语文     数学     英语     平均分     总分     挂科\n"); //gai
          printf("---------------------------------------------------------------------\n");
	      printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f%-10d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);
		  return p;	   
	   }
	   
	 }
	 printf("整个链表都没有！！\n");
	 return NULL;
   }
   return NULL;
}

struct role *search_id(struct role *h,int num)   //查找数据，根据编号
{
   struct role *p=NULL;
   
   if(h==NULL)
	   printf("链表为空，没有所需结点！\n");
   else
   {
	   for(p=h;p!=NULL;p=p->next)
	 {
	   if(p->id == num)
       {
	      printf("成功找到结点^_^\n");
		  printf("结点信息如下：\n");
		  printf("学号	  姓名	   性别     语文     数学     英语     平均分     总分     挂科\n"); //gai
          printf("---------------------------------------------------------------------\n");
	      printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);

		  return p;	   
	   }
	   
	 }
	 printf("整个链表都没有！！\n");
	 return NULL;
   }
   return NULL;
}