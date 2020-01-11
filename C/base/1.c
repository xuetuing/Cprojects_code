#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
unsigned random(int n)
{ int k=5;
    k=((k*159+23)%n)+1;
    return k;
  }
main()
{int num,
     guess,
     count;
 int n=100;
 char yes='Y';
 printf("\nNow let us play the game, guess the number.\n");
while(toupper(yes)=='Y')
{
  count=0;
  num=random(n);
do
{
  do
  {printf("\ninput yur number:");
   scanf("%d",&guess);
   }while(!(guess>=1&&guess<=100));
if(guess<num)
printf("your number is low! try again\n");
if(guess>num)
printf("your number is high! try again\n");
count++;
if(count==15)
{
printf("\nthe game is over,you can try again.");
system("pause");
exit(0);
  }
}while(!(guess==num));
if(count<=7)
printf("\nyou got it in %d time.",count);
else 
  {printf("\nyou got it in %d time,you can do better the next time!");
   printf("\n");
   }
   printf("\nNext?(Y/N):");
  scanf("%c",&yes);
   }
   system("pause");
   return 0;
}


