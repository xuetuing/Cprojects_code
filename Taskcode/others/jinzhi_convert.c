#include<stdio.h>
#include<string.h>
#include<math.h>
void dec_to_bin(int x); 
void dec_to_oct(int x);
void dec_to_hex(int x);
int main(void)  // ������У�int ռ��4���ֽ�- -
{
     int decNum;
     printf("������һ��ʮ����������\n");
     scanf("%d", &decNum);
     dec_to_bin(decNum);
     dec_to_oct(decNum);
     dec_to_hex(decNum);
     return 0;
}
void dec_to_bin(int x)   //10->2����
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
     printf("ʮ������%d <======>��Ӧ������Ϊ%s\n", num, array);  
}
void dec_to_oct(int x)   //10->8����
{
     char *table = "01234567";
     char array[12]; //�����趨Ϊ12.����Ϊ���˽�����֮�⣬���ǵ����������룬
                 //��ת��Ϊ������תΪ�˽���������32λÿ����ȡ���һ��8�����������Ԫ��Ϊ11����
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
     printf("ʮ������%d <======>��Ӧ�˽���Ϊ%s\n", num, array);  
}
void dec_to_hex(int x)   //10->16����
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
     printf("ʮ������%d <======>��Ӧʮ������Ϊ%s\n", num, array);
}