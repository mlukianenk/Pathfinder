#include "libmx.h"

char *mx_strdup(const char *str) {
	int str_len = mx_strlen(str);
	char *new = mx_strnew(str_len);

	return mx_strcpy(new, str);
}
