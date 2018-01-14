#include<stdio.h>

main()
{
  char user;
  int n=300000000;
  printf("输入信息：");
  while(1)
  {    
     scanf("%c",&user);
     getchar();
     printf("\n"); 
     if(user!='a')
    { printf("信息错误，重新输入："); 
     printf("\n");
     }
      else
	  {printf("完成验证！\n");
	     break;   
       }
      
               }   
    while(n--);  
      
      }
