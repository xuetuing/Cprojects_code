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
  printf("welcome ѧ����Ϣ����ϵͳ!\n");  //ѧ��
  printf("��ʾ�����뱾ϵͳ����������¼�����ݣ�\n");
  display2();
  printf("��ѡ���������(�����ִ�Сд)->");
  
  while(1)
  { 
	scanf("%c",&ch);//scanf("%c",ch);Ҫ����ע���������
	ch = toupper(ch);
    if(ch=='Q')
	{	
		printf("�˳��������\n");
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
		 case'A': printf("�����ڴ�����Ϣ��¼��\n"); //¼����Ϣ
			      lianbiao=creat(&sum);    //�˺�����Ҫ�з�ֹ�ظ��Ĺ���
                  printlianbiao(lianbiao,&sum);
                  display2();
                  printf("��ѡ���������->");
				  break;
		 case'B': lianbiao=insert(lianbiao,&sum);   //��������
			      printf("�������¼�¼���£�\n");
			      printlianbiao(lianbiao,&sum);
				  display2();
				  printf("��ѡ���������->");
				  break;
		 case'C': printf("��������Ҫ���ĵļ�¼��\n"); //�޸����ݣ���Ҫ������ʽ
			      modify(lianbiao);
			      printlianbiao(lianbiao,&sum);
				  display2();
				  printf("��ѡ���������->");
				  break;
		 case'D': printf("��������Ҫɾ���ļ�¼��\n");  // ɾ������
			      printf("��������->");
				  scanf("%d",&n);
			      lianbiao=del(lianbiao,n,&sum);
				  printf("ɾ�����������£�\n");
			      printlianbiao(lianbiao,&sum);
				  display2();
                  printf("��ѡ���������->");
				  break;
		 case'E': printf("��ѡ��Ҫ���ҵķ�ʽ��ѧ�ţ�����0��������������1����\n");  //��ѯ����,���Ӻ���
				  scanf("%d",&m);
				  if(m == 0)
				  {
					printf("������ѧ��->");
					scanf("%d",&n);
			        search_id(lianbiao,n);
			        display2();
				  }
				  if(m == 1)
				  {
					printf("����������->");
					scanf("%s",&xingming);
			        search_name(lianbiao,xingming);  //
			        display2();
				  }				  
                  printf("��ѡ���������->");
			      break;
		 case'F': printf("�����б�\n");           //��ʾ��Ϣ
			      printlianbiao(lianbiao,&sum);
			      display2();
                  printf("��ѡ���������->");
			      break;
		 case'G': printf("\n");                    //����
                  SaveTopc(lianbiao,&sum);
				  display2();
                  printf("��ѡ���������->");
			      break;
		 case'H': printf("\n");
			      beckup();
				  display2();
                  printf("��ѡ���������->");
			      break;
		 case'M': printf("\n");                    // ��������
			      lianbiao=Diaorudata(&sum);
				  printf("�����ļ��������£�\n\n");
				  printlianbiao(lianbiao,&sum);
				  display2();
                  printf("��ѡ���������->");
			      break;
		 /*case'J': printf("\n");                   //��ѯ
			      printf("�򿪲�ѯ���������Զ�ִ��Sql���!!\n");
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
                  printf("��ѡ���������->");
			      break; */
		 case'Q': printf("�˳����������");
	 }

	}
  } 

}