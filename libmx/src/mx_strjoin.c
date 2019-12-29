#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	int len1 = 0;
	int len2 = 0;
	char *new = NULL;

	if (!s1 || !s2)
		return NULL;
	len1 = mx_strlen(s1);
	len2 = mx_strlen(s2);
	new = mx_strnew(len1 + len2);
	if (new) {
		mx_strcpy(new, s2);
		mx_strcat(new, s1);
	}
	return new;
}
