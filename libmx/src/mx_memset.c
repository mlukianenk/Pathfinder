#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	char *new = (char*)b;
	
	while (len-- > 0) 
		*new++ = c;
	return b;
}
