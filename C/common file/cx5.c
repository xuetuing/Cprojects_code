#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int b[50],sum=0,i=0;
   int count=0;
   char c;
   printf("����������������ֵļ򵥼ӷ�����\n");
   printf("��������Ҫ�Ӻ͵����֣�");
   do{
       scanf("%d",&b[i]);
       i++;
       count++;
       scanf("%c",&c);
       }while(c!='\n');
   printf("��һ��������%d�����֡�\n",count);
   for(i=0;i<count;i++)
   {
     printf("������ĵ�%d�����ǣ�%d\n",i+1,b[i]);
     sum+=b[i];
     }
     printf("�����ܺ���: ");
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
