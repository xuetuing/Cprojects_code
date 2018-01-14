#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
struct student_type
{ char name[10];
  int num;
  int age;
       }stud[SIZE];
int main()
{FILE *fp;
  int i;
  if((fp=fopen("stu.txt","r"))==NULL)
  {printf("can't open file.\n");
    exit(0);
    }
    for(i=0;i<SIZE;i++)
    {fread(&stud[i],sizeof(struct student_type),1,fp);
     printf("%-5s %4d %4d\n",stud[i].name,stud[i].num,stud[i].age);
     
    }
    fclose(fp);
    system("pause");
    return 0;
}
