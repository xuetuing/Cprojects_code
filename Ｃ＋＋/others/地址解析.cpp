# include <stdio.h>
# include <stdlib.h> 
int main()
{
unsigned long input_IP;
unsigned int BeginByte,MidByte,ThirdByte,EndByte;
unsigned int_rotate=0x07; /*����������ѭ����λ�������޷�����*/
printf("********************************************************\n");
printf("** This program is to show how to parse a IP address**\n"); 
printf("********************************************************\n");
/*��ȡ��Ҫ������ʮ�����Ʊ�ʾ��1P��ַ*/ 
printf("Please enter the IP addrcss(hex) you want parse:"); 
scanf("%lx",&input_IP);
BeginByte =(input_IP >> 24) & ~(~0 << 8);/*��ȡ IP ��ַ�λ.*/
MidByte = (input_IP >> 16) & ~(~0 << 8);/*��ȡ IP ��ַ�м��*/
ThirdByte = (input_IP >>8 ) & ~(~0 <<8);/*��ȡ������.*/
EndByte = input_IP & ~(~0 << 8); /*�����һ��.*/
printf("********************************************************\n");
printf("The IP address after parsed is: %d,%d,%d,%d\n",BeginByte,MidByte,ThirdByte,EndByte);
/*��������ѭ����λ����.*/
printf("********************************************************\n");
printf("%u after rotated twice is =%u\n",int_rotate,_rotl(int_rotate,2));
printf("%u after rotated once is =%u\n",int_rotate,_rotr(int_rotate, 1));
system("pause");
return 0;
}
