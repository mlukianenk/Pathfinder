#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
	int count = 0;

	if (!str) 
		return -2;
	while (*str) {
		if (*str != c) {
			count++;
			str++;
		}
		if (*str == c)
			break;
		if (*str == '\0')
			return -1;
	}
	return count;
}
