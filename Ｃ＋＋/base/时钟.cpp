struct time {
unsigned char ti_min; 
unsigned char ti_hour;
unsigned char ti_hund; 
unsigned char ti_Sec; 
} 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include <conio.h> 
main()
{
  struct time curtime; 
     float th_hour,th_min,th_sec;
     do
     {   printf("*************************************\n");  
         printf("***This is a simple clock program.***\n"); 
         printf("***                               ***\n");
         printf("*************************************\n"); 
          printf("The current time is:\n");
           gettime(&curtime); /*得到当前系统时间 /*/ 
           if((float)curtime.ti_hour<= 12) /*.上午时间的处理*/
     {     printf("AM ");
           if((float)curtime.ti_hour<10) printf("0"); /*10 点之前在小时数前加零*/
            printf("%.Of:",(float)curtime.ti_hour);
     }
       else           /*午后的 处理*/
     {  printf("PM ");/*下午的时间处理*/ 
       if((float)curtime.ti_hour. 12<10) printf("0"); 
       printf("%.Of:",(float)curtime.ti_hour. 12);
     }
       if((float)curtime.ti_min< 10) printf("0");/* 显示分钟和秒 */ 
       printf("%.Of:",(float)curtime.ti_min ); 
       if((float)curtime.ti_sec< 10) printf("0"); 
       printf("%.Of",(float)curtime.ti_sec); 
       sleep(1); /*延时一秒后刷新*/ 
       clrscr(); /*清空屏幕等待下次输出时间*/
       } while(true);
       system("pause");
       return 0; 
     } 
