#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int b[50],sum=0,i=0;
   int count=0;
   char c;
   printf("本程序是任意个数字的简单加法器！\n");
   printf("请输入你要加和的数字：");
   do{
       scanf("%d",&b[i]);
       i++;
       count++;
       scanf("%c",&c);
       }while(c!='\n');
   printf("你一共输入了%d个数字。\n",count);
   for(i=0;i<count;i++)
   {
     printf("你输入的第%d个数是：%d\n",i+1,b[i]);
     sum+=b[i];
     }
     printf("数字总和是: ");
     printf("(");
     for(i=0;i<count-1;i++)
     {
      printf("%d",b[i]);
      printf("+");
      } 
      printf("%d",b[count-1]);
       printf(")");
      printf("=");
      printf("%d\n\n",sum);
   system("pause");
   return 0;
}
