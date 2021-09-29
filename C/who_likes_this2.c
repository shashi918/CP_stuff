#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *likes(size_t n, const char *const names[n])
{

    char *ret, *count_as_str;
    switch (n)
    {
    case 0:
        return strdup("no one likes this");
    case 1:
        ret = calloc(12 + strlen(names[0]), sizeof(char));
        sprintf(ret, "%s likes this", names[0]);
        return ret;
    case 2:
        ret = calloc(16 + strlen(names[0]) + strlen(names[1]), sizeof(char));
        sprintf(ret, "%s and %s like this", names[0], names[1]);
        return ret;
    case 3:
        ret = calloc(18 + strlen(names[0]) + strlen(names[1]) + strlen(names[2]), sizeof(char));
        sprintf(ret, "%s, %s and %s like this", names[0], names[1], names[2]);
        return ret;
    default:
        asprintf(&count_as_str, "%d", n - 2);
        ret = calloc(25 + strlen(names[0]) + strlen(names[1]) + strlen(count_as_str), sizeof(char));
        sprintf(ret, "%s, %s and %s others like this", names[0], names[1], count_as_str);
        return ret;
    }
}
