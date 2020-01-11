#include<stdio.h>
#include<stdlib.h>
#define N 30
void read_dat(int xx[N])
{
int i;
FILE *fp;
fp=fopen("input.dat","r");
for(i=0;i<N;i++)
fscanf(fp,"%d",&xx[i]);
fclose(fp);
}
main()
{ 
  int i,max,cnt,xx[N];
  float prj=0.0;
  cnt=0;
  read_dat(xx);
  max=xx[0];
  for(i=1;i<N;i++)
    if(max<xx[i])
    max=xx[i];
   for(i=0;i<N;i++)
   {if(xx[i]==max) cnt++;
   if(xx[i]%3==0||xx[i]%7==0) prj+=xx[i];
}
prj/=N;
   printf("max=%2d\ncnt=%2d\nprj=%6.2f",max,cnt,prj);
   system("pause");
   return 0;
} 
