#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int i,a,b,sum=0;
   printf("ʵ����������ֵļӷ�����\n");
   printf("��������Ҫʵ�ּӷ������ָ����� ");
   scanf("%d",&a);
   printf("������ÿ�����֣�\n");
   for(i=0;i<a;i++)
   {
     scanf("%d",&b);
     printf("������ĵ�%d�����ǣ�%d\n",i+1,b);
     }
   system("pause");
   return 0;
}
