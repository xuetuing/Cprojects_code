#include <stdio.h>
#include <stdlib.h>
main()
{ int s=1,n;
   printf("输入n=");
   scanf("%d",&n);
   if(n<0)   
   {printf("您输入的数值有误，请重新输入\n"); 
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
