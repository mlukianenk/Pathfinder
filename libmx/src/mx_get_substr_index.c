#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int count = 0;

	if (str == NULL || sub == NULL)
		return -2;
	if (mx_strstr(str, sub) == NULL)
		return -1;
	for (; str != mx_strstr(str,sub); str++) {
		count++;
	}
	return count;
}
