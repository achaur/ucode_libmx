#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int count = mx_count_words(s, c);
    char **str_split = (char **)malloc(count * sizeof(char *));
    int i, j = 0;

    if (!s) return NULL;
    while (j < count && s) {
        if (*s == c) 
            s++;
        else {
            for (i = 0; s[i] != c && *s; i++);
            char *str = malloc(i + 1);
            if (!str)  
                return NULL;
            else {
                str_split[j++] = mx_strncpy(str, s, i);
                s += i; 
            }
        }
    }
    str_split[j] = NULL;
    return str_split;
}
