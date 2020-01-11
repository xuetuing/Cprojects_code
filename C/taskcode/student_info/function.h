#ifndef FUNCTION_H
#define FUNCTION_H

struct role *insert(struct role *h,int *count);

void beckup();

void modify(struct role *h);

struct role *creat(int *count);

struct role *del(struct role *h,int number,int *count);

struct role *Diaorudata(int *sum);

void SaveTopc(struct role *head,int *count);

#endif