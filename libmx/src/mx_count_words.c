#include "libmx.h"

int mx_count_words(const char *str, char c) {
	int count = 0;
	int flag = 0;

	if (str == NULL)
        return -1;
	while (*str) {
		if (*str == c)
			flag = 0;
		else if (flag == 0) {
			flag = 1;
			count++;
		}
	str++;
	}
	return count;
}
