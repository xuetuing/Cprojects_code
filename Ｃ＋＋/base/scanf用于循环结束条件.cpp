#include<stdio.h>
#include<stdlib.h>  
main()
{
  int n,ss,cs,lower,upper;
  printf("Input the lower and the upper limits:");
   while(scanf("%d%d",&lower,&upper)==2)
   {
      printf("    n    square     cube\n");
       for(n=lower;n<=upper;n++)
  {
    ss=n*n;
    cs=n*n*n;
    printf("%5d%8d%9d\n",n,ss,cs);
    }
    printf("Input the lower and the upper limits:");
}
  system("pause");
   return 0;
      }
