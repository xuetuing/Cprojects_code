#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"shujuji.h"
#include"function.h"
#include"xianshi.h"
#include"find.h"
//#include"SQL.h"
//#include"yanzheng.h"

main()
{ 
  struct role *lianbiao=NULL;
  char ch,xingming[6];
  int n,m,sum=0;
  //int flag=0;
  //int getsqlnum=0;
  display1();
  //yanzheng();
  printf("welcome 学生信息管理系统!\n");  //学生
  printf("提示：进入本系统，建议首先录入数据！\n");
  display2();
  printf("请选择操作种类(不区分大小写)->");
  
  while(1)
  { 
	scanf("%c",&ch);//scanf("%c",ch);要更加注意这个错误！
	ch = toupper(ch);
    if(ch=='Q')
	{	
		printf("退出软件！！\n");
		break;
	}
	else if(ch=='\n')
	{
     printf("\n");
    }
   else
   {
	   switch(ch)
	 {
		 case'A': printf("您正在创建信息记录！\n"); //录入信息
			      lianbiao=creat(&sum);    //此函数需要有防止重复的功能
                  printlianbiao(lianbiao,&sum);
                  display2();
                  printf("请选择操作种类->");
				  break;
		 case'B': lianbiao=insert(lianbiao,&sum);   //增加数据
			      printf("插入后的新记录如下：\n");
			      printlianbiao(lianbiao,&sum);
				  display2();
				  printf("请选择操作种类->");
				  break;
		 case'C': printf("请输入你要更改的记录。\n"); //修改数据，需要其他方式
			      modify(lianbiao);
			      printlianbiao(lianbiao,&sum);
				  display2();
				  printf("请选择操作种类->");
				  break;
		 case'D': printf("请输入你要删除的记录。\n");  // 删除数据
			      printf("请输入编号->");
				  scanf("%d",&n);
			      lianbiao=del(lianbiao,n,&sum);
				  printf("删除后链表如下！\n");
			      printlianbiao(lianbiao,&sum);
				  display2();
                  printf("请选择操作种类->");
				  break;
		 case'E': printf("请选择要查找的方式，学号（输入0），姓名（输入1）！\n");  //查询数据,增加函数
				  scanf("%d",&m);
				  if(m == 0)
				  {
					printf("请输入学号->");
					scanf("%d",&n);
			        search_id(lianbiao,n);
			        display2();
				  }
				  if(m == 1)
				  {
					printf("请输入姓名->");
					scanf("%s",&xingming);
			        search_name(lianbiao,xingming);  //
			        display2();
				  }				  
                  printf("请选择操作种类->");
			      break;
		 case'F': printf("程序列表！\n");           //显示信息
			      printlianbiao(lianbiao,&sum);
			      display2();
                  printf("请选择操作种类->");
			      break;
		 case'G': printf("\n");                    //保存
                  SaveTopc(lianbiao,&sum);
				  display2();
                  printf("请选择操作种类->");
			      break;
		 case'H': printf("\n");
			      beckup();
				  display2();
                  printf("请选择操作种类->");
			      break;
		 case'M': printf("\n");                    // 读入数据
			      lianbiao=Diaorudata(&sum);
				  printf("数据文件内容如下；\n\n");
				  printlianbiao(lianbiao,&sum);
				  display2();
                  printf("请选择操作种类->");
			      break;
		 /*case'J': printf("\n");                   //查询
			      printf("打开查询分析器，自动执行Sql语句!!\n");
			      lianbiao=preSql(&sum);
				  printlianbiao(lianbiao,&sum);

                  GetSqlcommdword4(&flag);
				  GetSqlcommdword6(&flag,&getsqlnum);
                  
				  if(flag==1)
				  {
				    lianbiao=SqlForSelectAll(lianbiao,&sum);
				  }
				  else if(flag==3)
                  {
				    lianbiao=SqlForSelectone(lianbiao,getsqlnum);
				  }

				  display2();
                  printf("请选择操作种类->");
			      break; */
		 case'Q': printf("退出本软件！！");
	 }

	}
  } 

}