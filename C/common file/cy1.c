#include<stdio.h>
#include<stdlib.h>

void jisuanqi(void); 
void display(void);
void jiafa(int m,int n);
void jian(int m,int n);
void cheng(int m,int n);
void chu(int m,int n);

int a,b;

main()
{ 
   jisuanqi(); 
   system("pause");
   return 0;
   }
   
void jisuanqi(void)
{
  char d;
  printf("�๦�ܼ���������\n");
  printf("�����������������ѡ�����㣨+ - * /��.\n");
  printf("���롮E �����ߡ�e �������˳�����:  ");
  while(1)
  {
     scanf("%c",&d);
     if(d=='E'||d=='e')
     break;
     else if(d=='\n')
     printf("");
     else
     {            
        switch(d)
        {
           case'+': display();
                    jiafa(a,b);                    
                    break; 
           case'-': display();
                    jian(a,b);
                     break;
           case'*': display();
                    cheng(a,b);
                    break;
           case'/': display();
                    chu(a,b);
                     break;
           defaut: printf("������ַ����Ϸ������������룡\n");
                   break;       
                  }
             }     
          }
        }  
  
void display(void)
{ 
   printf("�������������֣�");
   scanf("%d %d",&a,&b);
   printf("������������ǣ�%d %d\n",a,b);  
     }
     
void jiafa(int m,int n)
{
   int k;
   k=m+n;
   printf("��ѡ����Ǽӷ����㣡");
   printf("������֮���ǣ�%d\n\n",k);
   printf("�����������������ѡ�����㣨+ - * /��.\n");
  printf("���롮E �����ߡ�e �������˳�����:  ");
   }
   
void jian(int m,int n)
{
  int k;
   k=m-n;
   printf("��ѡ����Ǽ������㣡");
   printf("������֮���ǣ�%d\n\n",k);
   printf("�����������������ѡ�����㣨+ - * /��.\n");
  printf("���롮E �����ߡ�e �������˳�����:  "); 
   }
   
void cheng(int m,int n)
{
   int k;
   k=m*n;
   printf("��ѡ����ǳ˷����㣡");
   printf("������֮���ǣ�%d\n\n",k);
   printf("�����������������ѡ�����㣨+ - * /��.\n");
  printf("���롮E �����ߡ�e �������˳�����:  "); 
   }
   
void chu(int m,int n)
{
   int k;
   k=m/n;
   printf("��ѡ����ǳ������㣡");
   printf("������֮���ǣ�%d\n\n",k);
   printf("�����������������ѡ�����㣨+ - * /��.\n");
  printf("���롮E �����ߡ�e �������˳�����:  "); 
   }
 
