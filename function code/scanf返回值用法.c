#include<stdio.h>
#include<stdlib.h>
const int max=100000;  
main()
{   
    int n,s;               //����status��������scanf�ķ���ֵ/
    s=0;
    printf("enter the number:"); //�� status=scanf("%d",&n);����/
    scanf("%d",&n);
    while(s<max)           //��while(status==1)���ж����������Խ����������ֵ�����/ 
    {   s=s+n;             //scanf���سɹ�������Ŀ�ĸ���������ɹ�����һ���ͷ��� 1/
       printf("\n�ܺ�Ϊ:%d\n",s);
       if(s>max)
      { printf("\n�տ��ѴﵽԤ�ڣ�\n");
         break;}
        printf("\nenter the number:");
        scanf("%d",&n);
    }
   system("pause");
   return 0;
} 
