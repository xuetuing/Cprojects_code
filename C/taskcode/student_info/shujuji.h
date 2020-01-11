#ifndef SHUJUJI_H
#define SHUJUJI_H

#define MAX_SIZE 50

struct role
{
  int id;       //number -> id,数组
  char name[6];
  char gender[MAX_SIZE];
  //int age;     //del
  //char job[MAX_SIZE];  
  //int wage;
  //char dizhi[MAX_SIZE];  
  //char marry[MAX_SIZE];
  //char beizhu[MAX_SIZE];
  float score[10]; //0 语文 1 数学 2 英语 3 政治.....
  float average;
  float scoresum;
  int failnum;  //挂科
  //char birthdate
  struct role *next;
};

#endif