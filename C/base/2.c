#include<stdio.h>
#include<stdlib.h>
unsigned random(n)
{ int k=5;
    k=((k*159+23)%n)+1;
  }
main()
{int n=100;
 int num;
 num=random(n);
 printf("%d\n",num);
 system("\npause");
 return 0;
 }
