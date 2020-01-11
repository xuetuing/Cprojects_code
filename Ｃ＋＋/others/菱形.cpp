#include <stdio.h>
#include <stdlib.h>
void putstar(int n);
void putspace(int n);
int  main(void)
{
    int column,i,j,half_column;
    printf("input the columns:\n");
    scanf("%d",&column);
    printf("start:\n");
    if((column % 2)==0) column--;
    half_column=column/2+1;
    for(i=1;i<=column;i++)
    {
        //打印上半部分
        if(i<=half_column)
        {
        putspace(half_column-i);
        putstar(2*i-1);
        putspace(half_column-i);
        printf("\n");
        }
        //下半部分
        else
        {
        putspace((column-(4*half_column-2*i-1))/2);
        putstar(4*half_column-2*i-1);
        putspace((column-(4*half_column-2*i-1))/2);
        printf("\n");   
        }
    }
    system("pause");
}

void putstar(int n)
{
    int i;
    for(i=0;i<n;i++) putchar('*');
    return;
}
void putspace(int n)
{
    int i;
    for(i=0;i<n;i++) putchar(' ');
    return;
    system("pause");
}


