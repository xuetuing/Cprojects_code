#ifndef SHUJUJI_H
#define SHUJUJI_H

#define MAX_SIZE 50

struct role
{
  int id;       //number -> id,����
  char name[6];
  char gender[MAX_SIZE];
  float score[10]; 
  float average;
  float scoresum;
  int failnum;  //�ҿ�
  //char birthdate
  struct role *next;
};

#endif