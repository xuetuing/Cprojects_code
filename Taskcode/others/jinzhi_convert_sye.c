
// first.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void D_B(int);
void D_O(int);
void D_X(int);
void B_D(int);
void B_O(int);
void B_X(int);
void O_B(int);
void O_D(int);
void O_X(int);
void X_B(char r[],int k);
void X_D(char r[],int k);
void X_O(char r[],int k);
void main()
{
 int i,j,k=0;
 int q;
 char r[10];
 printf("+=============================================================+\n");
 printf("|            ��  ӭ  ʹ  ��  ��  ��  ת  ��  ��  ��           |\n");
 printf("+=============================================================+\n");
 printf("  ע �� �� �� �� ֻ �� �� �� �� �� �� �� ת �� �� ��");
 do
 { 
  q=0;
  //fflush(stdin);
  printf("\n��ѡ����Ҫ��ת���Ľ���:/n0���˳�/n1��������/n2���˽���/n3��ʮ����/n4��ʮ������\n");
  scanf("%d",&i);
  switch (i)
  {
   case 1: printf("\n��ѡ��ת����Ľ���:/n0���˳�/n1��������/n2���˽���/n3��ʮ����/n4��ʮ������\n");
     scanf("%d",&j);
     switch(j)
     {
     case 1: printf("\nͬ����֮�䲻��ת����\n");
       q=1;
       break;
     case 2: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       B_O(k);
       q=1;
       break;
     case 3: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       B_D(k);
       q=1;
       break;
     case 4: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       B_X(k);
       q=1;
       break;
     case 0:
      
       printf("ллʹ�ã���");
       
     }
     break;
   case 2: printf("\n��ѡ��ת����Ľ���:/n0���˳�/n1��������/n2���˽���/n3��ʮ����/n4��ʮ������\n");
     scanf("%d",&j);
     switch(j)
     {
     case 2: printf("\nͬ����֮�䲻��ת����\n");
        q=1;
       break;
     case 1: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       O_B(k);
       q=1;
       break;
     case 3: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       O_D(k);
       q=1;
       break;
     case 4: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       O_X(k);
       q=1;
       break;
     case 0:
       printf("ллʹ�ã���");
     } 
     break;
   case 3: printf("\n��ѡ��ת����Ľ���:/n0���˳�/n1��������/n2���˽���/n3��ʮ����/n4��ʮ������\n");
     scanf("%d",&j);
     switch(j)
     {
     case 3: printf("\nͬ����֮�䲻��ת����/n");
        q=1;
      
       break;
     case 1: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       D_B(k);
       q=1;
       break;
     case 2: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       D_O(k);
       q=1;
       break;
     case 4: printf("\n����������Ҫת��������");
       scanf("%d",&k);
       D_X(k);
       q=1;
       break;
     case 0:
      
       printf("ллʹ�ã���");
     } 
     break;
   case 4: printf("\n��ѡ��ת����Ľ���:/n0���˳�/n1��������/n2���˽���/n3��ʮ����/n4��ʮ������\n");
     scanf("%d",&j);
     switch(j)
     {
     case 4: printf("\nͬ����֮�䲻��ת����\n");
        q=1;
       break;
     case 1: printf("\n����������Ҫת������:");
        fflush(stdin);
        gets(r);
        for(k=0;;k++)
        {
         if(r[k]=='/0')
         break;
        }
       
       X_B(r,k);
       q=1;
       break;
     case 2: printf("\n����������Ҫת������:");
       fflush(stdin);
        gets(r);
        for(k=0;;k++)
        {
         if(r[k]=='/0')
         break;
        }
       
       X_O(r,k);
       q=1;
       break;
     case 3: printf("\n����������Ҫת������:");
       fflush(stdin);
        gets(r);
        for(k=0;;k++)
        {
         if(r[k]=='/0')
         break;
        }
       X_D(r,k);
       q=1;
       break;
     case 0:
      printf("ллʹ�ã���");
       
     }
     break;
   case 0: printf("\nллʹ�ã�\n");
    
  }
 }while(q==1);
}
 ///////����Ϊ:  ������ת��Ϊʮ����,�˽���,ʮ������.
void B_D(int a)
{
 int i,s=0;
 int result=0;
 for(i=1;a!=0;i*=2)
 {
  if(a%10>1)
  { 
   s=1;
   break;
  }
  else
  {
   result+=(a%10)*i;
   a=a/10;
  }
 }
 if(s==1)
  printf("����������������������\n");
 else
 printf("\nת�������Ϊ��%d\n",result);
}
 
void B_O(int a)
{
 int i,j,k,s=0;
 int p[30];
 int result=0;
 for(i=1;a!=0;i*=2)
 {
  if(a%10>1)
  { 
   s=1;
   break;
  }
  else
  {
   result+=(a%10)*i;
   a=a/10;
  }
 }
 for(j=0;result!=0;j++)
 {
  p[j]=result%8;
  result=result/8;
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��");
  for(k=j-1;k>=0;k--)
  {
   printf("%d",p[k]);
  }
  printf("\n");
 } 
}
 

void B_X(int a)
{
 int i,j,k,s=0;
 char p[30];
 int result=0;
 for(i=1;a!=0;i*=2)
 {
  if(a%10>1)
  { 
   s=1;
   break;
  }
  else
  {
   result+=(a%10)*i;
   a=a/10;
  }
 }
 for(j=0;result!=0;j++)
 {
  p[j]=result%16;
  result=result/16;
  if (p[j]>10)
  {
   switch(p[j])
   {
   case 10: p[j]='A';
      break;
   case 11: p[j]='B';
      break;
   case 12:    p[j]='C';
      break;
   case 13:    p[j]='D';
      break;
   case 14:    p[j]='E';
      break;
   case 15:    p[j]='F';
      break;
   }
  }
  else p[j]+=48;
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��");
  for(k=j-1;k>=0;k--)
  {
   printf("%c",p[k]);
  }
  printf("\n");
 }
}
 ///////����Ϊ:  �˽���ת��Ϊ������,ʮ����,ʮ������.
void O_B(int a)
{
 int i,j,k,s=0;
 int result=0;
 int p[30];
 for(i=1;a!=0;i*=8)
 {if(a%10>7)
  { 
   s=1;
   break;
  }
  else
  {
   result+=(a%10)*i;
   a=a/10;
  }
 }
 for(j=0;result!=0;j++)
 {
  p[j]=result%2;
  result=result/2;
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��");
  for(k=j-1;k>=0;k--)
  {
   printf("%d",p[k]);
  }
  printf("\n");
 }
}
 
void O_D(int a)
{
 int i,s=0;
 int result=0;
 for(i=1;a!=0;i*=8)
 {
  if(a%10>7)
  { 
   s=1;
   break;
  }
  else
  {
   result+=(a%10)*i;
   a=a/10;
  }
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��%d\n",result);
 }
}
 
void O_X(int a)
{
 int i,j,k,s=0;
 char p[30];
 int result=0;
 for(i=1;a!=0;i*=8)
 {
  if(a%10>7)
  { 
   s=1;
   break;
  }
  else
  {
   result+=(a%10)*i;
   a=a/10;
  }
 }
 for(j=0;result!=0;j++)
 {
  p[j]=result%16;
  result=result/16;
  if(p[j]<10)
   p[j]+=48;
  else
  {
   switch(p[j])
   {
   case 10: p[j]='A';
      break;
   case 11: p[j]='B';
      break;
   case 12:    p[j]='C';
      break;
   case 13:    p[j]='D';
      break;
   case 14:    p[j]='E';
      break;
   case 15:    p[j]='F';
      break;
   }
  }
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��");
  for(k=j-1;k>=0;k--)
  {
   printf("%c",p[k]);
  }
  printf("\n");
 }
}
 ///////����Ϊ:  ʮ������ת��Ϊʮ����,������,�˽���.
void X_D(char a[],int k)
{
 int i,j,s=0;
 int result=0;
 int b[50];
 for(i=0;i<k;i++)
 {
  if(a[i]<='9'&&a[i]>='1')
  { b[i]=a[i]-48;
    
  }
  else
  {
   switch(a[i])
   {
   case 'A': b[i]=10;
      break;
   case 'B': b[i]=11;
      break;
   case 'C':   b[i]=12;
      break;
   case 'D':   b[i]=13;
      break;
   case 'E':   b[i]=14;
      break;
   case 'F':   b[i]=15;
      break;
   case 'a': b[i]=10;
      break;
   case 'b': b[i]=11;
      break;
   case 'c':   b[i]=12;
      break;
   case 'd':   b[i]=13;
      break;
   case 'e':   b[i]=14;
      break;
   case 'f':   b[i]=15;
      break;
   default:  s=1;
      
   }
   
  }
 }
 for(i=1,j=k-1;j>=0;j--,i*=16)
 {
  result+=b[j]*i;
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��%d",result);
 }
}
 

void X_B(char a[],int k)
{
 int i,j,s=0;
 int result=0;
 int b[50];
 int p[30];
 for(i=0;i<k;i++)
 {
  if(a[i]<='9'&&a[i]>='1')
   b[i]=a[i]-48;
  else
  {
   switch(a[i])
   {
   case 'A': b[i]=10;
      break;
   case 'B': b[i]=11;
      break;
   case 'C':   b[i]=12;
      break;
   case 'D':   b[i]=13;
      break;
   case 'E':   b[i]=14;
      break;
   case 'F':   b[i]=15;
      break;
   case 'a': b[i]=10;
      break;
   case 'b': b[i]=11;
      break;
   case 'c':   b[i]=12;
      break;
   case 'd':   b[i]=13;
      break;
   case 'e':   b[i]=14;
      break;
   case 'f':   b[i]=15;
      break;
   default: s=1;
      
   }
  }
 }
 for(j=k-1,i=1;j>=0;j--,i*=16)
 {
  result+=b[j]*i;
 }
  for(j=0;result!=0;j++)
 {
  p[j]=result%2;
  result=result/2;
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��");
  for(k=j-1;k>=0;k--)
  {
   printf("%d",p[k]);
  }
  printf("\n");
 }
}
 
void X_O(char a[],int k)
{
 int i,j,s=0;
 int result=0;
 int b[30];
 int p[30];
 for(i=0;i<k;i++)
 {
  if(a[i]<='9'&&a[i]>='1')
   b[i]=a[i]-48;
  else
  {
   switch(a[i])
   {
   case 'A': b[i]=10;
      break;
   case 'B': b[i]=11;
      break;
   case 'C':   b[i]=12;
      break;
   case 'D':   b[i]=13;
      break;
   case 'E':   b[i]=14;
      break;
   case 'F':   b[i]=15;
      break;
   case 'a': b[i]=10;
      break;
   case 'b': b[i]=11;
      break;
   case 'c':   b[i]=12;
      break;
   case 'd':   b[i]=13;
      break;
   case 'e':   b[i]=14;
      break;
   case 'f':   b[i]=15;
      break;
   default: s=1;
   }
  }
 }
 for(j=k-1,i=1;j>=0;j--,i*=16)
 {
  result+=b[j]*i;
 }
  for(j=0;result!=0;j++)
 {
  p[j]=result%8;
  result=result/8;
 }
 if(s==1)
  printf("����������������������\n");
 else
 {
  printf("\nת�������Ϊ��");
  for(k=j-1;k>=0;k--)
  {
   printf("%d",p[k]);
  }
  printf("\n");
 }
}
///////����Ϊ:  ʮ����ת��Ϊ������,�˽���,ʮ������.
void D_B(int a)
{
 int j,k;
 int p[30];
 for(j=0;a!=0;j++)
 {
  p[j]=a%2;
  a=a/2;
 }
 printf("\nת�������Ϊ��");
 for(k=j-1;k>=0;k--)
 {
  printf("%d",p[k]);
 }
 printf("\n");
}
 
void D_O(int a)
{
 int j,k;
 int p[30];
 for(j=0;a!=0;j++)
 {
  p[j]=a%8;
  a=a/8;
 }
 printf("\nת�������Ϊ��");
 for(k=j-1;k>=0;k--)
 {
  printf("%d",p[k]);
 }
 printf("\n");
}

void D_X(int a)
{
 int j,k;
 int p[30];
 for(j=0;a!=0;j++)
 {
  p[j]=a%16;
  a=a/16;
  if(p[j]<10)
   p[j]+=48;
  else
  {
   switch(p[j])
   {
   case 10: p[j]='A';
      break;
   case 11: p[j]='B';
      break;
   case 12:    p[j]='C';
      break;
   case 13:    p[j]='D';
      break;
   case 14:    p[j]='E';
      break;
   case 15:    p[j]='F';
      break;
   }
  }
 }
 printf("\nת�������Ϊ��");
 for(k=j-1;k>=0;k--)
 {
  printf("%c",p[k]);
 }
 printf("\n");
}




