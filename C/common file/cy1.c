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
  printf("多功能计算器！！\n");
  printf("请在以下运算符的中选择运算（+ - * /）.\n");
  printf("输入‘E ’或者‘e ’可以退出计算:  ");
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
           defaut: printf("输入的字符不合法，请重新输入！\n");
                   break;       
                  }
             }     
          }
        }  
  
void display(void)
{ 
   printf("请输入两个数字：");
   scanf("%d %d",&a,&b);
   printf("你输入的数字是：%d %d\n",a,b);  
     }
     
void jiafa(int m,int n)
{
   int k;
   k=m+n;
   printf("你选择的是加法运算！");
   printf("两个数之和是：%d\n\n",k);
   printf("请在以下运算符的中选择运算（+ - * /）.\n");
  printf("输入‘E ’或者‘e ’可以退出计算:  ");
   }
   
void jian(int m,int n)
{
  int k;
   k=m-n;
   printf("你选择的是减法运算！");
   printf("两个数之差是：%d\n\n",k);
   printf("请在以下运算符的中选择运算（+ - * /）.\n");
  printf("输入‘E ’或者‘e ’可以退出计算:  "); 
   }
   
void cheng(int m,int n)
{
   int k;
   k=m*n;
   printf("你选择的是乘法运算！");
   printf("两个数之积是：%d\n\n",k);
   printf("请在以下运算符的中选择运算（+ - * /）.\n");
  printf("输入‘E ’或者‘e ’可以退出计算:  "); 
   }
   
void chu(int m,int n)
{
   int k;
   k=m/n;
   printf("你选择的是除法运算！");
   printf("两个数之商是：%d\n\n",k);
   printf("请在以下运算符的中选择运算（+ - * /）.\n");
  printf("输入‘E ’或者‘e ’可以退出计算:  "); 
   }
 
