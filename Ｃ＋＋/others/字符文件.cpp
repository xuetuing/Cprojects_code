#include <stdio.h>
#include <stdlib.h>
int main()
{
  char ch,fname[10];
FILE*fp;
printf("�������õ��ļ�����");
scanf("%s",fname); 
if((fp=fopen(fname,"w"))==NULL)
{printf("���ܴ�%s�ļ�\n");
  exit (0); 
}
 ch=getchar(); 
 printf("����һ���洢�����̵��ַ�������#������:");
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
