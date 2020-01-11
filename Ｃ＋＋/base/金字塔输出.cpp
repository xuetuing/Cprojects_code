#include<stdio.h>
#include<stdlib.h>  
main()
{   
    int i,j,k,count;  
    char ch1,ch2;
    int num;
      printf("Input the word:");
      scanf("%c",&ch1);
      num=ch1-'A'+1;
    for(i=1;i<=num;i++) 
    {   count=i;
        while(count<30)    
       { printf(" ");
          count++;
          }
          ch2='A';
          for(j=0;j<i;j++) 
             printf("%c",ch2++);
             ch2-=2;
            for(k=i-1;k>0;k--)
             printf("%c",ch2--);
            printf("\n");
          }
   system("pause");
   return 0;
} 
