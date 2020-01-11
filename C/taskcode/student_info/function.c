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

	  printf("输入学号，学号为0 退出！\n");
	  printf("学号->");
	  scanf("%d",&(p->id));
   while(p->id !=0)
   {
		  printf("姓名->");
		  scanf("%s",p->name);

		  printf("性别->");
		  scanf("%s",p->gender);

		  printf("语文->");
		  scanf("%f",&(p->score[0]));

          printf("数学->");
		  scanf("%f",&(p->score[1]));

		  printf("英语->");
		  scanf("%f",&(p->score[2]));

		  p->scoresum =p->score[0]+p->score[1]+p->score[2];

		  p->average= p->scoresum/3; 

		  printf("挂科->");
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
          printf("输入编号，编号为0 退出！\n");
	      printf("编号->");
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

	  printf("请输入你要插入的新记录。\n");
	  printf("学号->");
	  scanf("%d",&(p->id));

	  printf("姓名->");
	  scanf("%s",p->name);

	  printf("性别->");
	  scanf("%s",p->gender);

	  printf("语文->");
	  scanf("%f",&(p->score[0]));

      printf("数学->");
	  scanf("%f",&(p->score[1]));

	  printf("英语->");
	  scanf("%f",&(p->score[2]));

	  p->scoresum =p->score[0]+p->score[1]+p->score[2];

      p->average= p->scoresum/3; 

	  printf("挂科->");
	  scanf("%d",&(p->failnum));
      
	  p->next=NULL; //p->next=NULL;这一步容易掉，很重要 切记！！尾结点

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
		tail->next=p;   //表示增加一个结点
		tail=p;        //尾节点相应后移一位
	  }
     (*count)++;
      
     return h;
}

void beckup()     //备份数据
{
  FILE *sourcefile=NULL,*endfile=NULL;
  char source[MAX_SIZE],end[MAX_SIZE];
  struct role *p=NULL;
  char ch;
  
  printf("请输入源文件名：");
  scanf("%s",source);
  sourcefile=fopen(source,"r");
  while(sourcefile == NULL)
   {
      printf("文件打开错误,请重新输入：");
	  scanf("%s",source);
      sourcefile=fopen(source,"r");
   }

  printf("请输入目的文件名：");
  scanf("%s",end);
  endfile=fopen(end,"w");
  while(endfile == NULL)
   {
      printf("目的文件打开错误,请重新输入：");
	  scanf("%s",end);
      endfile=fopen(end,"w");
   }

  for(ch=getc(sourcefile);ch!=EOF;ch=getc(sourcefile))
  {
    fputc(ch,endfile);
  }
  
  fclose(sourcefile);
  fclose(endfile);
 
  printf("文件备份成功!从%s到%s\n",source,end);

}

void modify(struct role *h)    //修改数据
{
  struct role *p=NULL;
  int m,xh;
  char name[6];
  printf("选择需要信息的学号（0）或者姓名（1）：");
  scanf("%d",m);
  if(m == 0)
  {
	printf("请输入学号:");
	scanf("%d",xh);
	p=search_id(h,xh);  //查询函数
  }
  else if (m == 1)
  {
	printf("请输入姓名:");
	scanf("%s",&name);
	p=search_name(h,name);  //查询函数
  }
  else return;
 
  if(p!=NULL)
  {
      printf("请输入新的对应信息：\n");

	  printf("学号->");
	  scanf("%d",&(p->id));

      printf("姓名->");
	  scanf("%s",p->name);

	  printf("性别->");
	  scanf("%s",p->gender);

	  printf("语文->");
	  scanf("%f",&(p->score[0]));

      printf("数学->");
	  scanf("%f",&(p->score[1]));

	  printf("英语->");
	  scanf("%f",&(p->score[2]));

	  p->scoresum =p->score[0]+p->score[1]+p->score[2];

      p->average= p->scoresum/3; 

	  printf("挂科->");
	  scanf("%d",&(p->failnum));
  }
}

struct role *del(struct role *h,int number,int *count)   //删除数据,
{
  struct role *p=NULL,*q=NULL;
   if(h==NULL)
   {
     printf("链表为空，不能删除！\n");
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
	   printf("整个链表都没有！\n");
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

struct role *Diaorudata(int *sum)    //读入数据
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
  
  printf("请输入文件路径名->");
  scanf("%s",source);
  sourcefile=fopen(source,"r");

  while(sourcefile==NULL)
  {
    printf("源文件打开失败，重新输入！\n");
	scanf("%s",source);
    sourcefile=fopen(source,"r");
  }
  printf("文件打开成功！\n");
  fscanf(sourcefile,"%s%s%s",shangtiao,title,xiatiao);
  fscanf(sourcefile,"%s",tongji);
  fscanf(sourcefile,"%d",&count); //
  fscanf(sourcefile,"%s",jilu);
  printf("调入数据成功！");
  //printf("数据内容如下：\n");
  fscanf(sourcefile,"%s",shanghtiao);
  fscanf(sourcefile,"%s%s%s%s%s%s%s%s%s",xuehao,xingm,gender,yuwen,shuxue,English,pingjun,zong,fail);

  *sum=count;

  if(count>0)
  {  
     p=(struct role *)malloc(sizeof(struct role));
     h=p; 
	 q=p;

	  fscanf(sourcefile,"%d",&(p->id));//注意取址符号
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
         fscanf(sourcefile,"%d",&(p->id));//注意取址符号
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
       printf("没有数据记录！\n");
	}
    fclose(sourcefile);
	
	return h;
}



void SaveTopc(struct role *head,int *count)   //保存数据
{
  FILE *outpointer=NULL;
  char Outname[MAX_SIZE];
  struct role *p=NULL;
  int i;

   printf("请输入文件名：");
   scanf("%s",Outname);

   outpointer=fopen(Outname,"w");

   while(outpointer == NULL)
   {
      printf("文件打开错误,请重新输入：");
	  scanf("%s",Outname);
      outpointer=fopen(Outname,"w");
   }
   fprintf(outpointer, "		    	*********************************\n");
   fprintf(outpointer, "				        学生信息管理系统         \n");
   fprintf(outpointer, "				*********************************\n");
   //fprintf(outpointer, "				作者：wangtjun                   \n");
   //fprintf(outpointer, "				时间：2014.09                    \n");
   //fprintf(outpointer, "				*********************************\n");
   fprintf(outpointer,"  统计共有  %d  条记录!\n",*count);
   fprintf(outpointer, "       -----------------------------------------------------------------------------\n");
   //fprintf(outpointer, "        编号	 姓名	  性别	   年龄	    工作     工资     婚否     地址      备注 \n");
   fprintf(outpointer, "        学号     姓名	  性别     语文     数学     英语     平均分    总分     挂科\n"); //gai

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
   
   printf("保存成功！\n");
}

int pop_sort(struct role *head)   //链表冒泡排序，节点交换法（还有换值法）；传入头节点指针   
{                           //排序中没有修改头节点指针值，只是修改指针内容head->next的值   
    struct role *pre,*p,*tail,*temp;  
    tail=NULL;  
    pre=head;  
      
    while((head->next->next)!=tail)//(head->next)!=tail同样适用 ，多执行最后一个步比较   
    {  
        p=head->next;  
        pre=head;  
        while(p->next!=tail)  
        {  
            if((p->scoresum)<(p->next->scoresum))   //修改n
            {  
            /*  pre->next=p->next; //交换节点方法一 
                p->next = p->next->next; 
                pre->next->next = p; 
                p = pre->next; */  
                  
                pre->next=p->next; //交换节点方法二   
                temp=p->next->next;  
                p->next->next=p;  
                p->next=temp;  
                p=pre->next;  //p回退一个节点   
                  
            }  
            p=p->next;  //p再前进一个节点   
            pre=pre->next;     
        }  
        tail=p;  
    }  
    return 0 ;  
}  