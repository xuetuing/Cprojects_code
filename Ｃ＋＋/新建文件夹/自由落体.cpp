#include<stdio.h>
#include<conio.h>
#include<time.h>
int main()
{ /*(X,y)��ʾ��������Ļ�ϵĳ�ʼλ�ã�depth��ʾ������غ󷴵����̶�, times��������ʱ����ӳ٣�
m���������˶��ķ���˵���������˶���˵���������˶�*/
int x=15,y=4,depth=20,timcs=20,m=1 ,i ,j;
for(;depth!=0;)
{
m=-m; 
if(m==1) depth--; 
for(i=1 ;i<=depth;i++)
{
printf("*****************************\n");
printf(" The program will show :\n"); 
printf(" the Free Falling |\n");
printf("*****************************\n"); 
gotoxy(x,y); 
printf("***\n");
goto(x,y+1);
printf("|*|\n"); 
gotoxy(x,y+2);
printf("***");
/*���Ʋ�ͬ���ӳ���ʾ��ʱ���С.*/ 
for(j= 1 ;j<=times;j++) 
delay(10);
clrscr();
if(m==-1)
{                      /*���������˶�*/ 
 y++; 
                  /*��ʱԽ��ԽС��˵���ٶ�Խ��Խ��.*/
 times--;
}
else/*���������˶�*/
{
y--;
                 /*ԽʱԽ��Խ��˵���ٶ�Խ��Խ��*/
times++��
}
}
}
getch()��
system("pause");
return 0;
}
