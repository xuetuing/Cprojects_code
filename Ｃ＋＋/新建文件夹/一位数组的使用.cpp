#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
main()
{
int i,ElecteeNum;
/*��������һά����ֱ��������꼶��ѡƱ��.*/ 
int GradeA[MAX],GradeB[MAX],GradeC[MAX];
/*����һά����ElecteelD�����ÿ����ѡ�ߵ���ݱ�ʾ*/
int ElecteeID[MAX];
/*���帡����һά��������Ÿ����꼶��ƽ��ѡƱ���*/
float VoteAverage[MAX];
printf("Input the num of the electees in the election:");
scanf("%d",&ElecteeNum);
if( ElecteeNum> 1&&ElecteeNum<MAX)
printf("Please input a ElecteelD and the votes of three grades:\n");
printf(" ElecteelD   GradeA   GradeB   GradeC\n");
/*����ÿ����ѡ�ߵ�ƽ��Ʊ��*/
for( i=0; i<ElecteeNum; i++ )
{
printf("No.%d>",i+1);
scanf("%d%d%d%d",&ElecteeID[i],&GradeA[i],&GradeB[i],&GradeC[i]);/*��������ʱΪ�˶������ʹ�ÿո� �Ը�ֵ��Ӱ�� */ 
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
