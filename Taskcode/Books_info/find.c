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
	   printf("����Ϊ�գ�û�������㣡\n");
   else
   {
	   for(p=h;p!=NULL;p=p->next)
	 {
	   if(p->name == name)
       {
	      printf("�ɹ��ҵ����^_^\n");
		  printf("�����Ϣ���£�\n");
          printf("ѧ��	  ����	   �Ա�     ����     ��ѧ     Ӣ��     ƽ����     �ܷ�     �ҿ�\n"); //gai
          printf("---------------------------------------------------------------------\n");
	      printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f%-10d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);
		  return p;	   
	   }
	   
	 }
	 printf("��������û�У���\n");
	 return NULL;
   }
   return NULL;
}

struct role *search_id(struct role *h,int num)   //�������ݣ����ݱ��
{
   struct role *p=NULL;
   
   if(h==NULL)
	   printf("����Ϊ�գ�û�������㣡\n");
   else
   {
	   for(p=h;p!=NULL;p=p->next)
	 {
	   if(p->id == num)
       {
	      printf("�ɹ��ҵ����^_^\n");
		  printf("�����Ϣ���£�\n");
		  printf("ѧ��	  ����	   �Ա�     ����     ��ѧ     Ӣ��     ƽ����     �ܷ�     �ҿ�\n"); //gai
          printf("---------------------------------------------------------------------\n");
	      printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);

		  return p;	   
	   }
	   
	 }
	 printf("��������û�У���\n");
	 return NULL;
   }
   return NULL;
}