#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int i,a,b,sum=0;
   printf("实现任意个数字的加法器。\n");
   printf("请输入您要实现加法的数字个数： ");
   scanf("%d",&a);
   printf("请输入每个数字：\n");
   for(i=0;i<a;i++)
   {
     scanf("%d",&b);
     printf("您输入的第%d个数是：%d\n",i+1,b);
     }
   system("pause");
   return 0;
}
