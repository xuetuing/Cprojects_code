#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
char xx[50][80];
int maxline=0;/*文章的总行数*/
int ReadDat(void);
void WriteDat(void);
void SortCharA(void)
{int i,j,k,strl;
char ch;
for(i=0;i<maxline;i++)
{   strl=strlen(xx[i]);
     for(j=0;j<strl-1;j++)
      for(k=j+1;k<strl;k++) 
        if(xx[i][j]>xx[i][k])
          {ch=xx[i][j]; xx[i][j]=xx[i][k]; xx[i][k]=ch;}
}
}
main()
{
 system("cls");
if(ReadDat()){
printf("数据文件IN.DAT不能打开！\n\007");
return 1;
}
SortCharA();
WriteDat();
}
int ReadDat(void)
{
FILE *fp;
int i=0;
char *p;
if((fp=fopen("IN.DAT","r"))==NULL) return 1;
while(fgets(xx[i],80,fp)!=NULL){
     p=strchr(xx[i],'\n');
     if(p)*p=0;
     i++;
}
 maxline=i;
fclose(fp);
return 0;
}
void WriteDat(void)
{
FILE *fp;
int i;
fp=fopen("OUT1.DAT","w");
for(i=0;i<maxline;i++){
     printf("%s\n",xx[i]);
     fprintf(fp,"%s\n",xx[i]);
}
fclose(fp);
   system("pause");
   return;
} 
