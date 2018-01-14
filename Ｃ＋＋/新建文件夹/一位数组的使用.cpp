#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
main()
{
int i,ElecteeNum;
/*定义三个一维数组分别存放三个年级的选票数.*/ 
int GradeA[MAX],GradeB[MAX],GradeC[MAX];
/*定义一维数组ElecteelD来存放每个候选者的身份标示*/
int ElecteeID[MAX];
/*定义浮点型一维数组来存放各个年级的平均选票结果*/
float VoteAverage[MAX];
printf("Input the num of the electees in the election:");
scanf("%d",&ElecteeNum);
if( ElecteeNum> 1&&ElecteeNum<MAX)
printf("Please input a ElecteelD and the votes of three grades:\n");
printf(" ElecteelD   GradeA   GradeB   GradeC\n");
/*计算每个候选者的平均票数*/
for( i=0; i<ElecteeNum; i++ )
{
printf("No.%d>",i+1);
scanf("%d%d%d%d",&ElecteeID[i],&GradeA[i],&GradeB[i],&GradeC[i]);/*输入数字时为了对齐可以使用空格 对赋值无影响 */ 
VoteAverage[i] = (GradeA[i]+GradeB[i]+GradeC[i])/3;
}
puts("EIecteeID   GradeA   GradeB   GradeC   VoteAverage"); 
for( i=0; i<ElecteeNum; i++ )
{
printf("%8d%8d%10d%10d%10.1f\n",ElecteeID[i],GradeA[i],GradeB[i],GradeC[i],VoteAverage[i]);
}
system("pause");
return 0;
}
