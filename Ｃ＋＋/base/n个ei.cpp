#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>  
main()
{
  char ch;
  printf("please Input the words:");
  while((ch=getchar())!='\n')
   putchar(ch);
  system("pause");
   return 0;
}
