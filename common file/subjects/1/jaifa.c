#include<stdio.h>

#include "jiafa.h"

int jia1,jia2;
void jiafa(void)
{
  printf("你选择了加法运算！！\n");
   printf("请输入两个数字：");
   scanf("%d%d",&jia1,&jia2);
    printf("你输入的两个数是：%d %d\n",jia1,jia2);
	printf("实现加和为：%d+%d=%d\n",jia1,jia2,jia1+jia2);
	
}
