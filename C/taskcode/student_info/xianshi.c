#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"xianshi.h"
#include"shujuji.h"

void display1()
{
   printf("			*************************************\n");
   printf("			ѧ     ��     ��     ��     ϵ     ͳ\n");
  // printf("			*************************************\n");
  // printf("			*���ߣ�wangtjun                     *\n");
  // printf("			*ʱ�䣺2014.09                      *\n");
   printf("			*************************************\n"); 
   printf("			*       ����������                  *\n");
   printf("			*��A����¼������                    *\n");
   printf("			*��B�������Ӽ�¼                    *\n");
   printf("			*��C�����޸ļ�¼                    *\n");
   printf("			*��D����ɾ����¼                    *\n");
   printf("			*��E������ѯ��¼                    *\n");
   printf("			*��F������ʾ��¼                    *\n");
   printf("			*��G������������                    *\n");
   printf("			*��H������������                    *\n");
   printf("			*��M������������                    *\n");
   printf("			*��J����������ѯ������              *\n");
   printf("			*��Q�����˳�!!!                     *\n");
   printf("			*************************************\n");
}

void display2()
{
   printf("			*************************************\n"); 
   printf("			*       ����������                  *\n");
   printf("			*��A�����������ݿ�                  *\n");
   printf("			*��B�������Ӽ�¼                    *\n");
   printf("			*��C�����޸ļ�¼                    *\n");
   printf("			*��D����ɾ����¼                    *\n");
   printf("			*��E������ѯ��¼                    *\n");
   printf("			*��F������ʾ��¼                    *\n");
   printf("			*��G������������                    *\n");
   printf("			*��H������������                    *\n");
   printf("			*��M������������                    *\n");
   printf("			*��J����������ѯ������              *\n");
   printf("			*��Q�����˳�!!!                     *\n");
   printf("			*************************************\n");
}

void printlianbiao(struct role *h,int *count)
{
   struct role *p=NULL;
   p=h;
   printf("ͳ�ƣ����� %d  ����¼!\n\n",*count);
   printf("ѧ��    ����    �Ա�    ����    ��ѧ    Ӣ��    ƽ����  �ܷ�    �ҿ�\n"); //gai
   printf("--------------------------------------------------------------------\n");
   while(p!=NULL)
   {
	   
	   printf("%-8d%-8s%-8s%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f%-8d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);
	   p=p->next;
   }
    printf("\n\n");
}