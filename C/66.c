#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include<stdlib.h>
char xx[50][80];
int maxline=0;/*文章的总行数*/
int ReadDat(void);
void WriteDat(void);
void StrOL(void) 
{ int i,j,k,s,m,strl;
char str[80];
for(i=0;i<maxline;i++)
    { strl=strlen(xx[i]);
memset(str,0,80); 
    s=k=0;
for(j=strl-1;j>=0;j--)   
    { if(isalpha(xx[i][j])) k++; 
     else { for(m=1;m<=k;m++)
str[s++]=xx[i][j+m];
                 k=0;     
            }
           if(!isalpha(xx[i][j])) 
str[s++]=' '; 
           }
for(m=1;m<=k;m++) 
       str[s++]=xx[i][j+m];
str[s]='\0';    
strcpy(xx[i],str);    }
}
void main()
{
if(ReadDat()){
printf("数据文件IN.DAT不能打开！\n\007");
return;
}
StrOL();
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
fp=fopen("OUT6.DAT","w");
for(i=0;i<maxline;i++){
     printf("%s\n",xx[i]);
     fprintf(fp,"%s\n",xx[i]);
}
fclose(fp);
system("pause");
}
