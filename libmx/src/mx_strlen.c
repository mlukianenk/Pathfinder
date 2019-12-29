#include "libmx.h"

int mx_strlen(const char *s) {
	int a = 0;

	while(s[a]) {
		a++;
	}
	return a;
}
