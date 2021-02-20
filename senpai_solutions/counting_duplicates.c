#include <stddef.h>
#include <string.h>

size_t duplicate_count(const char *s) {
  unsigned char map[0xff] = {0}, *c;
  size_t len = strlen(s), ret = 0;
  while (len--) {
    if (*(c = &map[(size_t)s[len] & 0x5fu]))
      *c = (*c < 2 && ret++) + 2;
    else
      *c = 1;
  }
  return ret;
}
