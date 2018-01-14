#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int a,b;
   char d;
   printf("本程序是简易多功能运算器\n");
   printf("请选择要进行的运算（+ - * /） 任一种\n");
   printf("输入'E'或'e'将退出本程序！\n");
   while(1)
   {
      scanf("%c",&d);
      if(d=='E'||d=='e')
      break;
      else if(d=='\n')
     { 
        printf("");
        }
     else
     {  
       switch(d)
      {   
         case'+':  printf("你选择了加法运算！\n");
                   printf("请输入两个数字：");
                   scanf("%d %d",&a,&b);
                   printf("两数之和是：%d+%d=%d\n\n",a,b,a+b);
                   printf("请选择要进行的运算（+ - * /） 任一种\n");
                   printf("输入'E'或'e'将退出本程序！\n");
                   break;
         case'-':  printf("你选择了减法运算！\n");
                   printf("请输入两个数字：");
                   scanf("%d %d",&a,&b);
                   printf("两数之差是：%d-%d=%d\n\n",a,b,a-b);
                   printf("请选择要进行的运算（+ - * /） 任一种\n");
                   printf("输入'E'或'e'将退出本程序！\n");
                   break;
         case'*':  printf("你选择了乘法运算！\n");
                   printf("请输入两个数字：");
                   scanf("%d %d",&a,&b);
                   printf("两数之积是：%d*%d=%d\n\n",a,b,a*b);
                   printf("请选择要进行的运算（+ - * /） 任一种\n");
                   printf("输入'E'或'e'将退出本程序！\n");
                   break;
         case'/':  printf("你选择了除法运算！\n");
                   printf("请输入两个数字：");
                   scanf("%d %d",&a,&b);
                   printf("两数之商是：%d/%d=%d\n\n",a,b,a/b);
                   printf("请选择要进行的运算（+ - * /） 任一种\n");
                   printf("输入'E'或'e'将退出本程序！\n");
                   break;
         default:  printf("输入的字符不合法，请重新输入！\n");
                   break;
                 }
         }
                         
      }
   
   printf("");
   system("pause");
   return 0;
} 
