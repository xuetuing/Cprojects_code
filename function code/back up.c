#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
int
main()
{ 
   char in_name[SIZE],out_name[SIZE];
   FILE *inp,*outp;
   char ch;
   printf("Enter the name you want to back up> ");
   for(scanf("%s",&in_name);
             (inp=fopen(in_name,"r"))==NULL;
              scanf("%s",&in_name))
              { printf("connot open %s for input\n",in_name);
                 printf("re-enter file name>");
                 }
                 printf("enter nanme for backup copy> ");
         for(scanf("%s",&out_name);
             (outp=fopen(out_name,"w"))==NULL;
              scanf("%s",&out_name))
              { printf("connot open %s for input\n",out_name);
                 printf("re-enter file name>");}       
         for(ch=getc(inp);ch!=EOF;ch=getc(inp))
          putc(ch,outp);
          fclose(inp);
          fclose(outp);
          printf("copied %s to %s.\n",in_name,out_name);
   system("pause");
   return 0;
}
