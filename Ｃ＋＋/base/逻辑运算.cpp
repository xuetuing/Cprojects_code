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
if ( X == y) /*�Ƚ�����*/
printf("X== y\n"); else printf("X!= y\n"); if(X!= z)
printf("X !=z\n"); else printf("X ==z\n");
if(X ==f) /*�Ƚ������͸�����*/
printf("X == f\n");else printf("X!= f\n"); if ( f ==h)
printf("f==h\n"); else printf("f!=h\n");
if( f == 25.095) /*�������Ƚϣ�ע�������еĸ�������ķǾ�ȷ��ʾ.*/ printf("f==25.095\n");  else printf("f!=25.095\n");
/* ��������ʾf!=25.095,�������ڼ������ʾ ������ʱ���ܾ�ȷ��ʾ*/ 
if ( fabs (f-25.095) <= 0.0001) /*��.���_���I��.���@�C�݈꘢䗙_����.*/ printf("f==25.095\n"); else printf("f!=25.095\n");
if ((X != y) && (f!=h ))/*����&&�aII...�Z���I�g�p*/ printf("X!=yandf!=h\n"); else if (( X!= z) || (h !=z))
printf("X != z or h != z\n");system("pause");
 return 0;
   
      } 
