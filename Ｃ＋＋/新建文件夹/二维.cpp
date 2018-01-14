#include <stdio.h>
#include <stdlib.h>
main()
{ int score[3][3];
   int i,j,n=1;
   puts("NUM   Am    Bm    Cm\n");
   for(i=0;i<3;i++)
   {  printf("NO.%d",i+1);
       for(j=0;j<3;j++)
         scanf("%d",&score[i][j]);
       }
   puts("NUM   Am    Bm    Cm\n");
       for(i=0;i<3;i++)
        { n=1;
            printf("NO.%d",i+1);
         for(j=0;j<3;j++)
          {printf("%5d",score[i][j]);
              if(n==3)    printf("\n");/*用于输出数据时对齐*/ 
              else     n++;
         }
         }
           system("pause");
        }
