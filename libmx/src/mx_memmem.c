#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, 
	const void *little, size_t little_len) 
{
	const char *b = (const char *) big;
	const char *l = (const char *) little;
 	char *b_new = mx_strndup(b, big_len);
	char *l_new = mx_strndup(l, little_len);

	if (big_len < little_len || !big || !little)
    	return NULL;
	if (little_len == 0)
    	return (void *)big;
	b_new = mx_strndup(b, big_len);
	l_new = mx_strndup(l, little_len);
	return mx_strstr(b_new, l_new);
}

