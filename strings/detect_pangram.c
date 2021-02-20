#include<stddef.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
bool is_pangram(const char *str_in) {

char map[0xff] = {0},*p, *r;
size_t i, n1 = strlen(str_in);

for ( i = 0; i < n1; i++)
{
  if(str_in[i]>='A' && str_in[i] <= 'Z')
  map[(size_t)str_in[i]+32] = 1;
  else
  map[(size_t)str_in[i]] = 1;
}
for ( i = 97; i <=122; i++)
{
  if(map[i]==0)
  return false;

}
return true;
}


int main() {
  bool a;
  char b[] = {"Cwm fjord bank glyphs vext quiz"};
  a = is_pangram(b);
  printf("a is %d",a);
  return 0;
}

