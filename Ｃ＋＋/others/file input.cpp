#include<stdio.h>
#include<stdlib.h>
#define a 2
#define b 3
main()
{ 
   int s[a][b];
   int i,j;
   int f1,f2,f3,status;
   FILE *file;
   file=fopen("bj.dat","r");
   for(status=fscanf(file,"%d%d%d",&f1,&f2,&f3);
      status==3;
      status=fscanf(file,"%d%d%d",&f1,&f2,&f3))
   s[f1][f2]=f3;
   for(i=0;i<2;i++)
   for(j=0;j<3;j++)
   printf("%d ",s[i][j]);
   system("pause");
   return 0;
}
