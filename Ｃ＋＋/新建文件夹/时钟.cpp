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
           gettime(&curtime); /*�õ���ǰϵͳʱ�� /*/ 
           if((float)curtime.ti_hour<= 12) /*.����ʱ��Ĵ���*/
     {     printf("AM ");
           if((float)curtime.ti_hour<10) printf("0"); /*10 ��֮ǰ��Сʱ��ǰ����*/
            printf("%.Of:",(float)curtime.ti_hour);
     }
       else           /*���� ����*/
     {  printf("PM ");/*�����ʱ�䴦��*/ 
       if((float)curtime.ti_hour. 12<10) printf("0"); 
       printf("%.Of:",(float)curtime.ti_hour. 12);
     }
       if((float)curtime.ti_min< 10) printf("0");/* ��ʾ���Ӻ��� */ 
       printf("%.Of:",(float)curtime.ti_min ); 
       if((float)curtime.ti_sec< 10) printf("0"); 
       printf("%.Of",(float)curtime.ti_sec); 
       sleep(1); /*��ʱһ���ˢ��*/ 
       clrscr(); /*�����Ļ�ȴ��´����ʱ��*/
       } while(true);
       system("pause");
       return 0; 
     } 
