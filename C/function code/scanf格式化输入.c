#include<stdio.h>
#include<stdlib.h>
const int pera=60;
main()
{   
    int min,mins,hour;
    printf("enter the number:");
    scanf("%d",&min);
    while(min>0)
    { hour=min/pera;
       mins=min%pera;
       printf("%2dminutes=%2dhours,%2dminutes\n",min,hour,mins);
        printf("enter the number:");
        scanf("%d",&min);
    }
    printf("���������޿ɲ����ԣ�������\n");
   system("pause");
   return 0;
} 
