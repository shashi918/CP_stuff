#include <stdbool.h>
#include <string.h>
bool isValidWalk(const char *walk)
{
    int c = strlen(walk);
    if (c > 10)
        return false;
    int ns = 0, ew = 0;
    if (c == 10)
    {
        while (*walk != '\0')
        {
            if (*walk == 'n')
            {
                ns++;
                walk++;
            }
            else if (*walk == 's')
            {
                ns--;
                walk++;
            }
            else if (*walk == 'w')
            {
                ew++;
                walk++;
            }
            else if (*walk == 'e')
            {
                ew--;
                walk++;
            }
        }

        if (ew == 0 && ns == 0)
            return true;
    }
    else
        return false;
}


// pro solution

#include <stdbool.h>

bool isValidWalk(const char *walk) {
  if (strlen(walk) != 10) return 0;
  
  int h = 0, v = 0;
  while(*walk) {
    switch(*walk) {
      case 'n': ++v; break;
      case 's': --v; break;
      case 'e': ++h; break;
      case 'w': --h; break;
    }
    ++walk;
  }
  return h == 0 && v == 0;
}