# include <stdio.h>
# include <stdlib.h> 
int main()
{
unsigned long input_IP;
unsigned int BeginByte,MidByte,ThirdByte,EndByte;
unsigned int_rotate=0x07; /*将用来调用循环移位操作的无符号数*/
printf("********************************************************\n");
printf("** This program is to show how to parse a IP address**\n"); 
printf("********************************************************\n");
/*获取需要解析的十六进制表示的1P地址*/ 
printf("Please enter the IP addrcss(hex) you want parse:"); 
scanf("%lx",&input_IP);
BeginByte =(input_IP >> 24) & ~(~0 << 8);/*获取 IP 地址最岛位.*/
MidByte = (input_IP >> 16) & ~(~0 << 8);/*获取 IP 地址中间段*/
ThirdByte = (input_IP >>8 ) & ~(~0 <<8);/*获取第三段.*/
EndByte = input_IP & ~(~0 << 8); /*获収最后一段.*/
printf("********************************************************\n");
printf("The IP address after parsed is: %d,%d,%d,%d\n",BeginByte,MidByte,ThirdByte,EndByte);
/*介绍两个循环移位困数.*/
printf("********************************************************\n");
printf("%u after rotated twice is =%u\n",int_rotate,_rotl(int_rotate,2));
printf("%u after rotated once is =%u\n",int_rotate,_rotr(int_rotate, 1));
system("pause");
return 0;
}
