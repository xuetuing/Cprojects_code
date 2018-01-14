#include <stdio.h>
#include <stdlib.h>
struct tm 
  { int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;}
void main()
{ time_t rawtime;
  struct tm*timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("current time is %s\n", asctime(timeinfo));
  exit(0);
}
¡¡¡¡
