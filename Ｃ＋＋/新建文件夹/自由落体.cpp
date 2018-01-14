#include<stdio.h>
#include<conio.h>
#include<time.h>
int main()
{ /*(X,y)表示货体在屏幕上的初始位置，depth表示物体落地后反弹的商度, times用来控制时间的延迟，
m用来控制运动的方向，说明是向下运动，说明是向上运动*/
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
/*控制不同的延迟显示的时间大小.*/ 
for(j= 1 ;j<=times;j++) 
delay(10);
clrscr();
if(m==-1)
{                      /*物体向下运动*/ 
 y++; 
                  /*延时越来越小，说明速度越来越快.*/
 times--;
}
else/*物体向上运动*/
{
y--;
                 /*越时越来越大，说明速度越来越慢*/
times++；
}
}
}
getch()；
system("pause");
return 0;
}
