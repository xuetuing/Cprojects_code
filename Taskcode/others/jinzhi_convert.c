#include<stdio.h>
#include<string.h>
#include<math.h>
void dec_to_bin(int x); 
void dec_to_oct(int x);
void dec_to_hex(int x);
int main(void)  // 计算机中，int 占用4个字节- -
{
     int decNum;
     printf("请输入一个十进制整数：\n");
     scanf("%d", &decNum);
     dec_to_bin(decNum);
     dec_to_oct(decNum);
     dec_to_hex(decNum);
     return 0;
}
void dec_to_bin(int x)   //10->2进制
{
     char *table="01";
     char array[33];
     int num;
     num = x;
     array[32] = '\0';
     int i = 31;
     if (x > 0)
     {  
          memset(array,'0',32);
          while(x)
          {
               array[i--] = table[x % 2];
               x = x/2;
          }
     }
     if (x < 0)
     {
          memset(array,'1',32);
          int j;
          for(j=0; j<32; j++)
          {
               array[i--] = table[x & 0x01];
               x >>= 1;
          }
     }
     printf("十进制数%d <======>对应二进制为%s\n", num, array);  
}
void dec_to_oct(int x)   //10->8进制
{
     char *table = "01234567";
     char array[12]; //数组设定为12.是因为除了结束符之外，考虑到负数的输入，
                 //其转化为补码再转为八进制数出，32位每三个取组成一个8进制数。因此元素为11个。
     int num;
     num = x;
     array[11] = '\0';
     int i = 10;
     if (x > 0)
     {
          memset(array,'0',11);
          while(x)
          {
               array[i--] = table[x % 8];
               x = x/8;
          }
      }
     if (x < 0)
     {
          memset(array,'1',11);  
          int j;
          for(j=0; j<10; j++)// 32/3 = 10;
          {
               array[i--] = table[x & 0x07];
               x >>= 3;
           }
          array[i] = table[x & 0x03];
     }
     printf("十进制数%d <======>对应八进制为%s\n", num, array);  
}
void dec_to_hex(int x)   //10->16进制
{
     char *table = "0123456789abcdef";
     char array[9];
     array[8] = '\0';
     int i = 7, num;
     num = x;
     if (x > 0)
     {
          memset(array,'0',8);
          while(x)
         {
              array[i--] = table[x % 16];
              x = x / 16 ;
         }
     }
     else
     {
          memset(array,'1',8);
          int j;
          for(j=0; j<8; j++)
          {
               array[i--] = table[x & 0x0f];
               x >>= 4;
           }
     }
     printf("十进制数%d <======>对应十六进制为%s\n", num, array);
}