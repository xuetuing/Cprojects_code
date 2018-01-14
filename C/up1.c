#include <conio.h>
#include <stdio.h>
#include<stdlib.h>
void readwriteDat();
int isP(int m)
{
int i;
for(i=2;i<m;i++)
   if(m % i==0)return 0;
return 1;
}
void num(int m,int k,int xx[])
{ int s=0;
  for(m=m+1;k>0;m++)
   if(isP(m)) { xx[s++]=m; k--;}
}
main()
{
  int m,n,xx[1000];
  system("cls");
  printf("\nPlease enter two integers:");
  scanf("%d%d",&m,&n);
  num(m,n,xx);
  for(m=0;m<n;m++)
  printf("%d ",xx[m]);
  printf("\n");
  readwriteDat();
}
void readwriteDat()
{
int m,n,xx[1000], i;
FILE *rf,*wf;
rf=fopen("in.dat","r");
wf=fopen("out.dat","w");
for(i=0;i<10;i++){
   fscanf(rf,"%d %d",&m,&n);
   num(m,n,xx);
   for(m=0;m<n;m++)fprintf(wf,"%d ",xx[m]);
   fprintf(wf,"\n");
}
fclose(rf);
fclose(wf);
system("pause");

}
