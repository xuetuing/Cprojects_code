 #include <stdio.h>
#include <stdlib.h>
#include<string.h>
main()
{int i=0;
  char str[80], fname[20];
FILE*fp;
printf("�����ļ�����");
scanf("%s",fname); 
if((fp=fopen(fname,"r"))==NULL)
{printf("���ܴ�%s�ļ�\n",fname);
  return 0; 
}
 while(fgets(str,80,fp)!=NULL)
    printf("%3d:%s",++i,str);
    fclose(fp);
      system("pause");
     } 
