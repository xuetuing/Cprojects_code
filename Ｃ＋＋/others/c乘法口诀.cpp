#include <stdio.h>
#include <stdlib.h>
main()
{int i,j,m;
   for(i=1;i<=9;i++)
   for(j=1;j<=i;j++)
     {m=i*j;
       printf("%2d*%d=%d",i,j,m);
       if(i==j)
       printf("\n");
       }
      system("pause");
      } 
