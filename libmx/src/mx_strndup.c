#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *new = mx_strnew(n);
	
	return mx_strncpy(new, s1, n);
}
