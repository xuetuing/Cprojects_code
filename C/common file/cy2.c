#include<stdio.h>
#include<stdlib.h>

int max(int a,int b,int c);
int min(int a,int b,int c);

main()
{ 
   int a,b,c;
   int m,n;
   printf("������ʵ�����ֵ��Сֵ���жϣ�\n");
   printf("������������");
   scanf("%d%d%d",&a,&b,&c);
   printf("��������������ǣ�%d %d %d\n",a,b,c);
    m=max(a,b,c);
    n=min(a,b,c);
    printf("���е����ֵ�ǣ�%d ,��Сֵ�ǣ�%d\n",m,n);
   system("pause");
   return 0;
}

int max(int a,int b,int c)
{
    int k;
     k=a;        
    if(b>k)
      k=b;   
     if(c>k)
     k=c;
    return k;
}

int min(int a,int b,int c)
{
      int k;
      k=a;
     if(b<k)
      k=b;
     if(c<k)
     k=c;
     return k;
}
