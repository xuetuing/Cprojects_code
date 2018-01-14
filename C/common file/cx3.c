#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int i,a,b[100],sum=0;
   printf("实现任意个数字的加法器。\n");
   printf("请输入您要实现加法的数字个数： ");
   scanf("%d",&a);
   printf("请输入每个数字：\n");
   for(i=0;i<a;i++)
   {
     scanf("%d",&b[i]);
     printf("您输入的第%d个数是：%d\n",i+1,b[i]);
     sum+=b[i];
     } 
     printf("数字之和是：");
     printf("(");
     for(i=0;i<a-1;i++)
     {
       printf("%d",b[i]);
       printf("+");
       }
     printf("%d",b[a-1]);
     printf(")");
     printf("=");
     printf("%d\n",sum); 
   system("pause");
   return 0;
}
