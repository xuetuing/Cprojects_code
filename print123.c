#include<stdio.h>
int main(  )
{  
	int f;
	int i,j,k,m;
	printf("ÊäÈëÐÐÊý: ");
	scanf("%d",&f);
	
	for(i=1;i<=f;i++)
	{
	  for(m=1;m<=f-i;m++)printf(" ");   
	  for(j=1;j<=i;j++)printf("%d",j);
	  for(k=j-2;k>=1;k--)printf("%d",k);
	  printf("\n");
	}

	for(i=1;i<=f;i++)
	{
	  for(m=1;m<=f-i;m++)printf(" ");   
	  for(j=1;j<=i;j++)printf("%d",i);
	  for(k=j-2;k>=1;k--)printf("%d",i);
	  printf("\n");
	}
}