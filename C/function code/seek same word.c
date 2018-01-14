int n=0;
char *p,*r;
while(*str)
{
 p=str; r=substr;
 while(*r)
 {
  if(*r==*p) {r++; p++;}
  else break;
  }
  if(*r=='\0') n++;
  str++;
  }
  return 0;
  
