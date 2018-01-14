#include <stdio.h>
#include<math.h>
int main(){
    int n,m,j,k,s;
    char i[64];
    do {
        printf("\n\n你想要: [0]右三角\n%8c[1]正三角\n%8c[2]正方形\n%8c[3]倒三角\n%8c[4]左三角\n%8c[5]左箭头\n",32,32,32,32,32);
        scanf("%d",&s);
    }
    while(s<0||s>5);
    do printf("\n你想要边长(建议2-9)?\n");
    while(!scanf("%d",&n),n<0);
    if (s==1||s==3)    s/=j=s++;
    for(m=n;n>0&&j!=3;n--){
        sprintf(i,"\n%%%dc",s*n);
        printf(i,32);
        for (k=n*2-2;k<m*2-1;k++) 
            printf(" %c",90-m+n+abs(m+n-2-k));// printf(" %c",90-m+n);
    }
   for(n+=2,m+=(j==3);m>1&&j!=1;m--){
        sprintf(i,"\n%%%dc",s*n++);
        printf(i,32);
        for (k=m*2-3;k>0;k--)
            printf(" %c",92-m+abs(m-1-k));//printf(" %c",92-m);
    }
    return main();
    system("pause");
}


