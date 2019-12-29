#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	unsigned char *new = (unsigned char *) s;
	
	for (size_t i = 0; i < n; i++) {
		if (new[i] == c)
			return (new + i);
	}
	return NULL;
}
