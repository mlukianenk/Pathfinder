#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	int count = 0;
	int len = mx_strlen(sub);
	int i = 0;

	if (sub == NULL || str == NULL) 
		return -1;
	while (str[i]) {
		if (str[i] == sub[0] && mx_strncmp(str, sub, len) == 0) {
			count ++;
		}
		i++;
	}
	return count;
}
