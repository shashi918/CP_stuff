#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool solution(const char *string, const char *ending)
{
  int f;
  int c = strlen(string);
  int d = strlen(ending);
  if(c<d)
    return false;
  else
  f = strcmp(string+c-d,ending);
    if(f==0)
      return true;
  else 
    return false;
}
