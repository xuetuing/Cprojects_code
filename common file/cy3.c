#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int n1,n2,sum=0;
   int ji,i,a[2];
   printf("ʵ�������������\n");
   printf("����������(��һ����С�ڵڶ���)��\n");
   printf("��һ����ʾ�����ϵף��ڶ�����ʾ�����µף�");
   scanf("%d%d",&n1,&n2);
   printf("��������������ǣ�%d %d\n",n1,n2);
   for(i=0;i<n2-n1+1;i++)
   {
     printf("�������%d�����\n",i+1);
     scanf("%d%d",&a[0],&a[1]);
     printf("������ĵ�%d���ǣ� %d*%d\n",i+1,a[0],a[1]);
     ji=cheng(a[0],a[1]);
     sum=add(ji,sum);
     } 
    printf("���������ܺ�Ϊ��%d\n\n",sum);
   system("pause");
   return 0;
}

int cheng(int c,int d)
{  
    int k;
    k=c*d;
    return k;
    }
    
int add(int c,int d)
{
  int k;
  k=c+d;
  return k;
  }





