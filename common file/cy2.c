#include<stdio.h>
#include<stdlib.h>

int max(int a,int b,int c);
int min(int a,int b,int c);

main()
{ 
   int a,b,c;
   int m,n;
   printf("本程序实现最大值最小值的判断！\n");
   printf("输入三个数：");
   scanf("%d%d%d",&a,&b,&c);
   printf("你输入的三个数是：%d %d %d\n",a,b,c);
    m=max(a,b,c);
    n=min(a,b,c);
    printf("其中的最大值是：%d ,最小值是：%d\n",m,n);
   system("pause");
   return 0;
}

int max(int a,int b,int c)
{
    int k;
     k=a;        
    if(b>k)
      k=b;   
     if(c>k)
     k=c;
    return k;
}

int min(int a,int b,int c)
{
      int k;
      k=a;
     if(b<k)
      k=b;
     if(c<k)
     k=c;
     return k;
}
