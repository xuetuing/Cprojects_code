#include <stdio.h>
#include <stdlib.h>
main()
{ FILE*fp1,*fp2;
   fp1=fopen("d:\file1.txt","r");
   fp2=fopen("d:\file2.txt","w");
   while(!feof(fp1)) putchar(getc(fp1));
   putchar(10);
   rewind(fp1);
   while(!feof(fp1))  putc(getc(fp1),fp2);
   fclose(fp1);fclose(fp2);
   system("pause");
   return 0;
} 
