#include<stdio.h> 
#include <stdlib.h>
 main() 
{ int m,n,x1,x2,a,b,c; 
        x1=1;x2=1; 
        printf("请输入m,n:"); 
        scanf("%d,%d",&m,&n); 
        c=(m>n)?m:n; 
        while(x1<=c) 
        { 
                if(m%x1==0 && n%x1==0) 
                { 
                        a=x1; 
                } 
                x1++; 
        }

        if(a!=1)
        { 
                while(m*x2%n!=0) 
                { 
                        x2++; 
                } 
                b=m*x2; 
        } 
        else b=m*n;

        printf("最大公约数为%d\n最小公倍数为%d\n",a,b);
        system("pause");

} 
