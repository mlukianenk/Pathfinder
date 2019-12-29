#include "libmx.h"

char *mx_strtrim(const char *str) {
	int len = mx_strlen(str);
	char *new = NULL;

	while (mx_isspace(str[len - 1]) && len > 0) {
		len--;
	}
	while (mx_isspace(*str) && len > 0) {
		str++;
		len--;
	}
	new = mx_strnew(len);
	return mx_strncpy(new, str, len);
}
