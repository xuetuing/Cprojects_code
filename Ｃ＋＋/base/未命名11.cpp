#include<stdio.h>
#include<stdlib.h> 
#define MAX 20
int a[MAX];
void readDat();
void writedat();
main()
{
   int i;
   readDat();
   writedat();
  system("pause");
   return 0;
}
void readDat()
{
  FILE *fp;
  int i;
  fp=fopen("in20.dat","r");
   for(i=0;i<MAX;i++) fscanf(fp,"%d",&a[i]);
   fclose(fp);
}
void writedat()
{
  int i;
  FILE *fp;
  fp=fopen("PUT20.dat","w");
  for(i=0;i<MAX;i++)
  fprintf(fp," %d",a[i]);
  fclose(fp);
}
