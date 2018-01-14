#include <stdio.h>
#include <stdlib.h>
int main()
{
  char ch,fname[10];
FILE*fp;
printf("输入所用的文件名：");
scanf("%s",fname); 
if((fp=fopen(fname,"w"))==NULL)
{printf("不能打开%s文件\n");
  exit (0); 
}
 ch=getchar(); 
 printf("输入一个存储到磁盘的字符串（以#结束）:");
 ch=getchar();
 while(ch!='#')
 {fputc(ch,fp);
    putchar(ch);
    ch=getchar();
}

    fclose(fp);
    putchar(10);
    system("pause");
    return 0;
     } 
