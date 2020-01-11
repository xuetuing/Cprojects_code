#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"xianshi.h"
#include"shujuji.h"

void display1()
{
   printf("			*************************************\n");
   printf("			学     生     管     理     系     统\n");
  // printf("			*************************************\n");
  // printf("			*作者：wangtjun                     *\n");
  // printf("			*时间：2014.09                      *\n");
   printf("			*************************************\n"); 
   printf("			*       操作帮助！                  *\n");
   printf("			*【A】：录入数据                    *\n");
   printf("			*【B】：增加记录                    *\n");
   printf("			*【C】：修改记录                    *\n");
   printf("			*【D】：删除记录                    *\n");
   printf("			*【E】：查询记录                    *\n");
   printf("			*【F】：显示记录                    *\n");
   printf("			*【G】：保存数据                    *\n");
   printf("			*【H】：备份数据                    *\n");
   printf("			*【M】：读入数据                    *\n");
   printf("			*【J】：启动查询分析器              *\n");
   printf("			*【Q】：退出!!!                     *\n");
   printf("			*************************************\n");
}

void display2()
{
   printf("			*************************************\n"); 
   printf("			*       操作帮助！                  *\n");
   printf("			*【A】：创建数据库                  *\n");
   printf("			*【B】：增加记录                    *\n");
   printf("			*【C】：修改记录                    *\n");
   printf("			*【D】：删除记录                    *\n");
   printf("			*【E】：查询记录                    *\n");
   printf("			*【F】：显示记录                    *\n");
   printf("			*【G】：保存数据                    *\n");
   printf("			*【H】：备份数据                    *\n");
   printf("			*【M】：调入数据                    *\n");
   printf("			*【J】：启动查询分析器              *\n");
   printf("			*【Q】：退出!!!                     *\n");
   printf("			*************************************\n");
}

void printlianbiao(struct role *h,int *count)
{
   struct role *p=NULL;
   p=h;
   printf("统计：共有 %d  条记录!\n\n",*count);
   printf("学号    姓名    性别    语文    数学    英语    平均分  总分    挂科\n"); //gai
   printf("--------------------------------------------------------------------\n");
   while(p!=NULL)
   {
	   
	   printf("%-8d%-8s%-8s%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f%-8d\n",p->id,p->name,p->gender,p->score[0],p->score[1],p->score[2],p->average,p->scoresum,p->failnum);
	   p=p->next;
   }
    printf("\n\n");
}