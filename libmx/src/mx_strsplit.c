#include "libmx.h"

static int s_countword(const char *str, char c) {
	int count = 0;

	while (*str) {
		if (*str != c) {
			count++;
		}
		if (*str == c) {
			break;
		}
		str++;
	}
	return count;
}

char **mx_strsplit(const char *s, char c) {
	int j = 0;
	int count = 0;
	int len = 0;
	char **new = NULL;

	count = mx_count_words(s, c);
	new = (char **)malloc ((count + 1) * sizeof(char *));
	while (*s != '\0') {
		if (*s == c)
			s++;
		else if (*s != c) {
			len = s_countword(s, c);
			new[j] = mx_strnew(len);
			mx_strncpy(new[j], s, len);
			j++;
			s += len;
		}
	}
    new[j] = NULL;
	return new;
}
