#include "libmx.h"

static void delall_space(char *buf, int *len);

char *mx_del_extra_spaces(const char *str) {
	int j = 0;
	int len = 0;
	char *new = NULL;
	char *box = NULL;

	if (!str)
		return NULL;
	box = mx_strtrim(str);
	len = mx_strlen(box);
	delall_space(box, &len);
	new = mx_strnew(len);
	for (int i = 0; box[i] != '\0'; i++) {
		if (mx_isspace(box[i]) && mx_isspace(box[i + 1]))
			continue;
		new[j++] = box[i];
	}
	mx_strdel(&box);
	return new;
}

static void delall_space(char *buf, int *len) {
    for (int i = 0; buf[i] != '\0'; i++) {
        if (mx_isspace(buf[i]) && mx_isspace(buf[i + 1])) {
            len--;
        }
    }
}
