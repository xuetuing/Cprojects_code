#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int g,a,b,c,d,i;
    c = 39;
    d = 1;
    while (true)
    {
    printf ("���������εĸ�\n");
    scanf ("%d", &g);
    if ( g < 4)
        printf ("�ߴ���3\n");
    else if ( g % 2 == 0)
        printf ("�߲���Ϊż����\n");
    else
    {
        for (i = 0; i < g/2;i++)
        {
            for (a = 0; a < c;a++)
            printf (" ");
            for (b = 0 ; b < d;b++)
                printf ("*");
            c--;
            d +=2;
            printf ("\n");
        }
        c++;
        d-=2;
         for (i = 0; i < g/2-1; i++)
        {
            c++;
            d -= 2;
            for (a = 0; a < c; a++)
                printf (" ");
            for (b = 0; b < d; b++)
                printf ("*");
            printf ("\n");
        }
    }
    }    
        return 0;
         system("pause");
} 
