#include "libmx.h"

void mx_str_reverse(char *s) {
	int count = mx_strlen(s);

	for (int i = 0; i < count / 2; i++) {
		char temp = s[i];
		s[i] = s[count - i - 1];
		s[count - i - 1] = temp;
	}
}
