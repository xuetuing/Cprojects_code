 #include <stdio.h>
#include <stdlib.h>
#include<string.h>
main()
{int i=0;
  char str[80], fname[20];
FILE*fp;
printf("输入文件名：");
scanf("%s",fname); 
if((fp=fopen(fname,"r"))==NULL)
{printf("不能打开%s文件\n",fname);
  return 0; 
}
 while(fgets(str,80,fp)!=NULL)
    printf("%3d:%s",++i,str);
    fclose(fp);
      system("pause");
     } 
