#include <stddef.h>
#include<string.h>
#include<stdio.h>

#include <stddef.h>
#include<string.h>
size_t duplicate_count(const char *text) {
    char map[0xff] = {0};
    int t=0;
    size_t size = strlen(text);
   for (int i = 0; i < size; i++)
   {
      if(text[i]>='A' && text[i]<='Z')
      map[(size_t)text[i]+32]+= 1;
      else
      map[(size_t)text[i]]+= 1;
   }
   for (int i = 0; i < 255; i++)
   {
      if(map[i]>=2)
      t++;
   }
   return t;
}

int main() {
   char s[] = {"Abcde"};
   char t[] = {"abCdea"};
   char u[] = {"indivisIbility"};
   duplicate_count(s);
   duplicate_count(t);
   duplicate_count(u);
   return 0;
}