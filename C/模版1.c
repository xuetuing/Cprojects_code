#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
struct student_type
{ char name[10];
  int num;
  int age;
  }stud[SIZE];
void save()
{FILE *fp;
  int i;
  if((fp=fopen("stu.txt","w"))==NULL)
  {printf("can't open file.\n");
    return;
    }
    for(i=0;i<SIZE;i++)
    if(fwrite(&stud[i],sizeof(struct student_type),1,fp)!=1)
     printf("file write error.\n");
     fclose(fp);
     }    
main()
{ int i; 
   FILE *fp;
  printf("please enter data of students:\n");
  for(i=0;i<SIZE;i++)
  scanf("%s%d%d",stud[i].name,&stud[i].num,&stud[i].age);
  save();
  printf("\n文件中的数据为：\n");
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
