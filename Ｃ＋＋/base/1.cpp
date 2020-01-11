#include<stdio.h>
#include<stdlib.h>
#define M 3
#define N 3
int score[M][N];
float a_stu[M];
void search(int (*p)[N])
{int flag,i,j;
  for(i=0;i<M;i++)
{flag=0;
  for(j=0;j<N;j++)
  if(*(p[i]+j)<60)
    flag=1;
    if(flag==1)
    {printf("\nthe No.%d student have failed subjects.",i+1);
     printf("\nthe scores of No.%d is: ",i+i);
     for(j=0;j<N;j++)
     printf("%5.1d",*(p[i]+j));
}
 }
  }
 
main()
{ 
  int i,j;
  void aver_stu(void);
  for(i=0;i<M;i++)
  {printf("\ninput the scores of the No.%d student:",i+1);
    for(j=0;j<N;j++)
   scanf("%d",&score[i][j]);
   } 
   aver_stu();
   printf("\nNo.  ");
    for(j=0;j<N;j++)
    printf("cour%d   ",j+1); printf("aver");
    for(i=0;i<M;i++)
    {printf("\nNo.%d  ",i+1);
     for(j=0;j<N;j++)
     printf("%d     ",score[i][j]);
     printf("%.2f",a_stu[i]);
     }
   search(score);
   system("pause");
   return 0;
} 
void aver_stu(void)
{int i,j;
  float s;
 for(i=0;i<M;i++)
 {
  for(j=0,s=0;j<N;j++)
   s+=score[i][j];
    a_stu[i]=s/3.0;
   }
   }
