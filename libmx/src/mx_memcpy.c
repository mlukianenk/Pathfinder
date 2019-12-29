#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	unsigned char *new = (unsigned char *) dst;
	unsigned char *s = (unsigned char *) src;	
	
	for (size_t i = 0; i < n; i++) {
		new[i] = s[i];
	}
	return (void *)dst;
}
