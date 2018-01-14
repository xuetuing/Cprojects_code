# include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int main()
{
int X = 25, y = 25 ,z = 30;
float f= 25.095, h = 25.095;
printf("**********************************\n"); 
printf("** This is a logical calculator: **\n");
printf("**********************************\n"); 
if ( X == y) /*比较整数*/
printf("X== y\n"); else printf("X!= y\n"); if(X!= z)
printf("X !=z\n"); else printf("X ==z\n");
if(X ==f) /*比较整数和浮点数*/
printf("X == f\n");else printf("X!= f\n"); if ( f ==h)
printf("f==h\n"); else printf("f!=h\n");
if( f == 25.095) /*浮点数比较，注意计算机中的浮点变量的非精确表示.*/ printf("f==25.095\n");  else printf("f!=25.095\n");
/* 运算结果显示f!=25.095,这是由于计算机表示 浮点数时不能精确表示*/ 
if ( fabs (f-25.095) <= 0.0001) /*斾.晜揰悢揑惓.橍朄丆嵼堦槩錀檁撪斾.*/ printf("f==25.095\n"); else printf("f!=25.095\n");
if ((X != y) && (f!=h ))/*墘帵&&榓II...嶼晞揑巊梡*/ printf("X!=yandf!=h\n"); else if (( X!= z) || (h !=z))
printf("X != z or h != z\n");system("pause");
 return 0;
   
      } 
