#include<stdio.h>
#include <stdlib.h>
void simpleDebug (int i,char ch,float f1,char a_char[],int a_int[],int size,int option)
{ 
int j;
switch(option)
{
    case 1:
    printf("The int value is %d\n",i);
    break;
    case 2:
    break; /*输出浮点型*/
    printf("The char is %c\n",ch);
    case 3:
    printf(" The float value is %f\n " , f1) ;
    break;
/*编出字符型数组或者是一个字符串*/ 
  case 4: 
  {printf("The char array is\n");
for(j=0;j<size;j++)
printf(" %c",a_char[j]);
printf("\n");
break;
}
/*输出整型数组*/
case 5:
{ printf("Thc integer array is:\n");
for(i=0;j<size;++j) printf("%d",a_int[j]); 
printf("\n"); 
break;
}
default:
printf("Option Error!\n"); break;
}
printf(" Please press any key to continue:\n"); 
}
 main()
{int i,j,a_int[8]; char ch,a_char[8]; float fl;
char *string="l love china";
   for(i=0;i<8;i++)
   {
a_int[i]=i+1;
}
for(j=0;j<8;j++)
{
a_char[j]=(char)(j+65);
}
ch='x';
fl=6.5;
simpleDebug (i,0,0,0,0,0,1);
simpleDebug (0,ch,0,0,0,0,2);
simpleDebug (0,0,fl,0,0,0,3);
simpleDebug (0,0,0,a_char,0,8,4);
 simpleDebug (0,0,0,string,0,13,4);
 simpleDebug (0,0,0,0,a_int,8,3);
 simpleDebug (0,0,0,0,0,0,10);
 system("pause");
}
