#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"shujuji.h"
#include"function.h"
#include"xianshi.h"
#include"find.h"

struct role *creat(int *count)
{
   struct role *head=NULL;
   struct role *p=NULL;
   struct role *tail=NULL;
   p=(struct role *)malloc(sizeof(struct role));

	  printf("����ѧ�ţ�ѧ��Ϊ0 �˳���\n");
	  printf("ѧ��->");
	  scanf("%d",&(p->id));
   while(p->id !=0)
   {
		  printf("����->");
		  scanf("%s",p->name);

		  printf("�Ա�->");
		  scanf("%s",p->gender);

		  printf("����->");
		  scanf("%f",&(p->score[0]));

          printf("��ѧ->");
		  scanf("%f",&(p->score[1]));

		  printf("Ӣ��->");
		  scanf("%f",&(p->score[2]));

		  p->scoresum =p->score[0]+p->score[1]+p->score[2];

		  p->average= p->scoresum/3; 

		  printf("�ҿ�->");
		  scanf("%d",&(p->failnum));
   
          if(head==NULL)
		  {
		      head=p;
			  tail=p;
		  }
		  else
		  {
		      tail->next=p;
			  tail=p;
		  }
 
          (*count)++;
		  
		  p=(struct role *)malloc(sizeof(struct role));
          printf("�����ţ����Ϊ0 �˳���\n");
	      printf("���->");
	      scanf("%d",&(p->id));
   }
   tail->next=NULL;  
   return head;
}

struct role *insert(struct role *h,int *count)
{ 
	  struct role *p=NULL,*tail=NULL;
	  struct role *q=NULL;
	  p=(struct role *)malloc(sizeof(struct role));

	  printf("��������Ҫ������¼�¼��\n");
	  printf("ѧ��->");
	  scanf("%d",&(p->id));

	  printf("����->");
	  scanf("%s",p->name);

	  printf("�Ա�->");
	  scanf("%s",p->gender);

	  printf("����->");
	  scanf("%f",&(p->score[0]));

      printf("��ѧ->");
	  scanf("%f",&(p->score[1]));

	  printf("Ӣ��->");
	  scanf("%f",&(p->score[2]));

	  p->scoresum =p->score[0]+p->score[1]+p->score[2];

      p->average= p->scoresum/3; 

	  printf("�ҿ�->");
	  scanf("%d",&(p->failnum));
      
	  p->next=NULL; //p->next=NULL;��һ�����׵�������Ҫ �мǣ���β���

	  if(h==NULL)
	  {
	     h=p;
		 tail=p;
	  }
      else
	  {
	    for(q=h;q!=NULL;q=q->next)
		{
		   tail=q;
		}
		tail->next=p;   //��ʾ����һ�����
		tail=p;        //β�ڵ���Ӧ����һλ
	  }
     (*count)++;
      
     return h;
}

void beckup()     //��������
{
  FILE *sourcefile=NULL,*endfile=NULL;
  char source[MAX_SIZE],end[MAX_SIZE];
  struct role *p=NULL;
  char ch;
  
  printf("������Դ�ļ�����");
  scanf("%s",source);
  sourcefile=fopen(source,"r");
  while(sourcefile == NULL)
   {
      printf("�ļ��򿪴���,���������룺");
	  scanf("%s",source);
      sourcefile=fopen(source,"r");
   }

  printf("������Ŀ���ļ�����");
  scanf("%s",end);
  endfile=fopen(end,"w");
  while(endfile == NULL)
   {
      printf("Ŀ���ļ��򿪴���,���������룺");
	  scanf("%s",end);
      endfile=fopen(end,"w");
   }

  for(ch=getc(sourcefile);ch!=EOF;ch=getc(sourcefile))
  {
    fputc(ch,endfile);
  }
  
  fclose(sourcefile);
  fclose(endfile);
 
  printf("�ļ����ݳɹ�!��%s��%s\n",source,end);

}

void modify(struct role *h)    //�޸�����
{
  struct role *p=NULL;
  int m,xh;
  char name[6];
  printf("ѡ����Ҫ��Ϣ��ѧ�ţ�0������������1����");
  scanf("%d",m);
  if(m == 0)
  {
	printf("������ѧ��:");
	scanf("%d",xh);
	p=search_id(h,xh);  //��ѯ����
  }
  else if (m == 1)
  {
	printf("����������:");
	scanf("%s",&name);
	p=search_name(h,name);  //��ѯ����
  }
  else return;
 
  if(p!=NULL)
  {
      printf("�������µĶ�Ӧ��Ϣ��\n");

	  printf("ѧ��->");
	  scanf("%d",&(p->id));

      printf("����->");
	  scanf("%s",p->name);

	  printf("�Ա�->");
	  scanf("%s",p->gender);

	  printf("����->");
	  scanf("%f",&(p->score[0]));

      printf("��ѧ->");
	  scanf("%f",&(p->score[1]));

	  printf("Ӣ��->");
	  scanf("%f",&(p->score[2]));

	  p->scoresum =p->score[0]+p->score[1]+p->score[2];

      p->average= p->scoresum/3; 

	  printf("�ҿ�->");
	  scanf("%d",&(p->failnum));
  }
}

struct role *del(struct role *h,int number,int *count)   //ɾ������,
{
  struct role *p=NULL,*q=NULL;
   if(h==NULL)
   {
     printf("����Ϊ�գ�����ɾ����\n");
     return h;
   }
   else
   {
     p=h;
     while(p!=NULL && p->id != number)
	 {
	   q=p;
	   p=p->next;	 
	 }   
     if(p==NULL)
	 {
	   printf("��������û�У�\n");
	 }
	 else
	 {
	   if(p==h)
	   h=p->next;
	   else
		 q->next=p->next;
	  
	    free(p);
		(*count)--;
	 }
	 
   }
   return h;    
}

struct role *Diaorudata(int *sum)    //��������
{
  struct role *h=NULL;
  struct role *p=NULL;
  struct role *q=NULL;
  FILE *sourcefile=NULL;
  char source[MAX_SIZE];
  int i,count;
  char shangtiao[MAX_SIZE],title[MAX_SIZE],xiatiao[MAX_SIZE];
  char tongji[MAX_SIZE],jilu[MAX_SIZE];
  char shanghtiao[MAX_SIZE],xiahtiao[MAX_SIZE];
  char xuehao[MAX_SIZE],xingm[MAX_SIZE],gender[MAX_SIZE],yuwen[MAX_SIZE],shuxue[MAX_SIZE],English[MAX_SIZE],pingjun[MAX_SIZE],zong[MAX_SIZE],fail[MAX_SIZE];
  
  printf("�������ļ�·����->");
  scanf("%s",source);
  sourcefile=fopen(source,"r");

  while(sourcefile==NULL)
  {
    printf("Դ�ļ���ʧ�ܣ��������룡\n");
	scanf("%s",source);
    sourcefile=fopen(source,"r");
  }
  printf("�ļ��򿪳ɹ���\n");
  fscanf(sourcefile,"%s%s%s",shangtiao,title,xiatiao);
  fscanf(sourcefile,"%s",tongji);
  fscanf(sourcefile,"%d",&count); //
  fscanf(sourcefile,"%s",jilu);
  printf("�������ݳɹ���");
  //printf("�����������£�\n");
  fscanf(sourcefile,"%s",shanghtiao);
  fscanf(sourcefile,"%s%s%s%s%s%s%s%s%s",xuehao,xingm,gender,yuwen,shuxue,English,pingjun,zong,fail);

  *sum=count;

  if(count>0)
  {  
     p=(struct role *)malloc(sizeof(struct role));
     h=p; 
	 q=p;

	  fscanf(sourcefile,"%d",&(p->id));//ע��ȡַ����
	  fscanf(sourcefile,"%s",p->name);
	  fscanf(sourcefile,"%s",p->gender);
	  fscanf(sourcefile,"%f",&(p->score[0]));
	  fscanf(sourcefile,"%f",&(p->score[1]));
	  fscanf(sourcefile,"%f",&(p->score[2]));
	  fscanf(sourcefile,"%f",&(p->average));
	  fscanf(sourcefile,"%f",&(p->scoresum));
	  fscanf(sourcefile,"%d",&(p->failnum));
	  p->next=NULL;

	  for(i=1;i<count;i++)
	  {
	     p=(struct role *)malloc(sizeof(struct role));
         fscanf(sourcefile,"%d",&(p->id));//ע��ȡַ����
		 fscanf(sourcefile,"%s",p->name);
		 fscanf(sourcefile,"%s",p->gender);
		 fscanf(sourcefile,"%f",&(p->score[0]));
		 fscanf(sourcefile,"%f",&(p->score[1]));
		 fscanf(sourcefile,"%f",&(p->score[2]));
		 fscanf(sourcefile,"%f",&(p->average));
		 fscanf(sourcefile,"%f",&(p->scoresum));
		 fscanf(sourcefile,"%d",&(p->failnum));
		 p->next=NULL;

		 q->next=p;
	     q=p;
	  }
         fscanf(sourcefile,"%s",xiahtiao);
		 printf("gain data succed!\n");
  }
    else
	{
       printf("û�����ݼ�¼��\n");
	}
    fclose(sourcefile);
	
	return h;
}



void SaveTopc(struct role *head,int *count)   //��������
{
  FILE *outpointer=NULL;
  char Outname[MAX_SIZE];
  struct role *p=NULL;
  int i;

   printf("�������ļ�����");
   scanf("%s",Outname);

   outpointer=fopen(Outname,"w");

   while(outpointer == NULL)
   {
      printf("�ļ��򿪴���,���������룺");
	  scanf("%s",Outname);
      outpointer=fopen(Outname,"w");
   }
   fprintf(outpointer, "		    	*********************************\n");
   fprintf(outpointer, "				        ѧ����Ϣ����ϵͳ         \n");
   fprintf(outpointer, "				*********************************\n");
   //fprintf(outpointer, "				���ߣ�wangtjun                   \n");
   //fprintf(outpointer, "				ʱ�䣺2014.09                    \n");
   //fprintf(outpointer, "				*********************************\n");
   fprintf(outpointer,"  ͳ�ƹ���  %d  ����¼!\n",*count);
   fprintf(outpointer, "       -----------------------------------------------------------------------------\n");
   //fprintf(outpointer, "        ���	 ����	  �Ա�	   ����	    ����     ����     ���     ��ַ      ��ע \n");
   fprintf(outpointer, "        ѧ��     ����	  �Ա�     ����     ��ѧ     Ӣ��     ƽ����    �ܷ�     �ҿ�\n"); //gai

   p=head;
   for(i=0;i<(*count);i++)
   {
     //fprintf(outpointer, "       %-8d%-10s%-10s%-8d%-10s%-8d%-10s%-10s%-10s\n",p->number,p->name,p->gender,p->age,p->job,p->wage,p->marry,p->dizhi,p->beizhu);
     fprintf(outpointer, "       %-10d%-10s%-10s%-10.2f%%-10.2f%-10.2f%-10.2f%-10.2f%-10d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);

	 p=p->next;
   }
   fprintf(outpointer, "       -----------------------------------------------------------------------------\n");
 
   printf("\n\n");
      
   fclose(outpointer);
   
   printf("����ɹ���\n");
}

int pop_sort(struct role *head)   //����ð�����򣬽ڵ㽻���������л�ֵ����������ͷ�ڵ�ָ��   
{                           //������û���޸�ͷ�ڵ�ָ��ֵ��ֻ���޸�ָ������head->next��ֵ   
    struct role *pre,*p,*tail,*temp;  
    tail=NULL;  
    pre=head;  
      
    while((head->next->next)!=tail)//(head->next)!=tailͬ������ ����ִ�����һ�����Ƚ�   
    {  
        p=head->next;  
        pre=head;  
        while(p->next!=tail)  
        {  
            if((p->scoresum)<(p->next->scoresum))   //�޸�n
            {  
            /*  pre->next=p->next; //�����ڵ㷽��һ 
                p->next = p->next->next; 
                pre->next->next = p; 
                p = pre->next; */  
                  
                pre->next=p->next; //�����ڵ㷽����   
                temp=p->next->next;  
                p->next->next=p;  
                p->next=temp;  
                p=pre->next;  //p����һ���ڵ�   
                  
            }  
            p=p->next;  //p��ǰ��һ���ڵ�   
            pre=pre->next;     
        }  
        tail=p;  
    }  
    return 0 ;  
}  