#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int i,a,b[100],sum=0;
   printf("ʵ����������ֵļӷ�����\n");
   printf("��������Ҫʵ�ּӷ������ָ����� ");
   scanf("%d",&a);
   printf("������ÿ�����֣�\n");
   for(i=0;i<a;i++)
   {
     scanf("%d",&b[i]);
     printf("������ĵ�%d�����ǣ�%d\n",i+1,b[i]);
     sum+=b[i];
     } 
     printf("����֮���ǣ�");
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
