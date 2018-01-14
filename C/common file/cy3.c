#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int n1,n2,sum=0;
   int ji,i,a[2];
   printf("实现有限项级数！！\n");
   printf("输入两个数(第一个数小于第二个)，\n");
   printf("第一个表示级数上底，第二个表示级数下底：");
   scanf("%d%d",&n1,&n2);
   printf("你输入的两个数是：%d %d\n",n1,n2);
   for(i=0;i<n2-n1+1;i++)
   {
     printf("请输入第%d项级数！\n",i+1);
     scanf("%d%d",&a[0],&a[1]);
     printf("你输入的第%d项是： %d*%d\n",i+1,a[0],a[1]);
     ji=cheng(a[0],a[1]);
     sum=add(ji,sum);
     } 
    printf("级数各项总和为：%d\n\n",sum);
   system("pause");
   return 0;
}

int cheng(int c,int d)
{  
    int k;
    k=c*d;
    return k;
    }
    
int add(int c,int d)
{
  int k;
  k=c+d;
  return k;
  }





