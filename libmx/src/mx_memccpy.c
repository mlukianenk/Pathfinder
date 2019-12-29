#include "libmx.h"
#include "string.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	unsigned char *d = dst;
	unsigned const char *s = src;

	while (n--) {
		*d = *s;
		if (*d == c)
			return (d + 1);
		++d; 
		++s;
	}
	return NULL;
}
