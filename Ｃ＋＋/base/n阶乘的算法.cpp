#include <stdio.h>
#include <stdlib.h>
main()
{ int s=1,n;
   printf("����n=");
   scanf("%d",&n);
   if(n<0)   
   {printf("���������ֵ��������������\n"); 
           system("pause");
           return 0;
          } 
   if(n==0)     
   {printf("n!=1\n"); 
           system("pause");
           return 0;
          }      
   while(n>=1) 
   {  s=s*n;
      n--;
   }
   printf("n!=%d\n",s);
      system("pause");
      return 0; 
      }
