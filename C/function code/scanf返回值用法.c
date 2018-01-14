#include<stdio.h>
#include<stdlib.h>
const int max=100000;  
main()
{   
    int n,s;               //设置status变量接收scanf的返回值/
    s=0;
    printf("enter the number:"); //用 status=scanf("%d",&n);代码/
    scanf("%d",&n);
    while(s<max)           //用while(status==1)作判断条件，可以解决解决非数字的问题/ 
    {   s=s+n;             //scanf返回成功读入项目的个数，如果成功读入一个就返回 1/
       printf("\n总和为:%d\n",s);
       if(s>max)
      { printf("\n收款已达到预期！\n");
         break;}
        printf("\nenter the number:");
        scanf("%d",&n);
    }
   system("pause");
   return 0;
} 
