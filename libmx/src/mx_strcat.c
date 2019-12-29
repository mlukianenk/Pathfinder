#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
	int len = mx_strlen(s1);
	char *end = s1 + len;

	while (*s2 != '\0') {
		*end++ = *s2++;
	}
	*end = '\0';
	return s1;
}
