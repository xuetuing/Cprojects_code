#include<stdio.h>
#include<stdlib.h>
main()
{ 
   int a,b;
   char d;
   printf("�������Ǽ��׶๦��������\n");
   printf("��ѡ��Ҫ���е����㣨+ - * /�� ��һ��\n");
   printf("����'E'��'e'���˳�������\n");
   while(1)
   {
      scanf("%c",&d);
      if(d=='E'||d=='e')
      break;
      else if(d=='\n')
     { 
        printf("");
        }
     else
     {  
       switch(d)
      {   
         case'+':  printf("��ѡ���˼ӷ����㣡\n");
                   printf("�������������֣�");
                   scanf("%d %d",&a,&b);
                   printf("����֮���ǣ�%d+%d=%d\n\n",a,b,a+b);
                   printf("��ѡ��Ҫ���е����㣨+ - * /�� ��һ��\n");
                   printf("����'E'��'e'���˳�������\n");
                   break;
         case'-':  printf("��ѡ���˼������㣡\n");
                   printf("�������������֣�");
                   scanf("%d %d",&a,&b);
                   printf("����֮���ǣ�%d-%d=%d\n\n",a,b,a-b);
                   printf("��ѡ��Ҫ���е����㣨+ - * /�� ��һ��\n");
                   printf("����'E'��'e'���˳�������\n");
                   break;
         case'*':  printf("��ѡ���˳˷����㣡\n");
                   printf("�������������֣�");
                   scanf("%d %d",&a,&b);
                   printf("����֮���ǣ�%d*%d=%d\n\n",a,b,a*b);
                   printf("��ѡ��Ҫ���е����㣨+ - * /�� ��һ��\n");
                   printf("����'E'��'e'���˳�������\n");
                   break;
         case'/':  printf("��ѡ���˳������㣡\n");
                   printf("�������������֣�");
                   scanf("%d %d",&a,&b);
                   printf("����֮���ǣ�%d/%d=%d\n\n",a,b,a/b);
                   printf("��ѡ��Ҫ���е����㣨+ - * /�� ��һ��\n");
                   printf("����'E'��'e'���˳�������\n");
                   break;
         default:  printf("������ַ����Ϸ������������룡\n");
                   break;
                 }
         }
                         
      }
   
   printf("");
   system("pause");
   return 0;
} 
