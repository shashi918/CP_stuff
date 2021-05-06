#include <stdio.h>
#include <string.h>

char* factors(int lst) {
    char result[100000] = {0};
    for(int i=2, j=0; i<= lst; i++, j=0) {
      while (lst%i==0){
        j++;
        lst=lst/i;
      }
        if (j>1) 
          sprintf(strlen(result)+result, "(%d**%d)", i, j);
        else if (j==1)
          sprintf(strlen(result)+result, "(%d)", i);
    }
    return result;
}


//more solution 

#include <math.h>
#include <stdio.h>

int divide(int* n, int d) {
  int c = 0;
  while (*n % d == 0) {
    *n /= d;
    ++c;
  }
  return c;
}

char* factors(int n) {
  char* s = malloc(64 * sizeof(char));
  char* e = s + 64;
  char* b = s;
  for (int d = 2; d <= n; ++d) {
    int c = divide(&n, d);
    if (c == 0) continue;
    b += c > 1 ? snprintf(b, e - b, "(%d**%d)", d, c)
               : snprintf(b, e - b, "(%d)", d);
  }
  return s;
}