#include "libmx.h"

char *mx_strnew(const int size) {
	char *location = NULL;
	
	location = (char *)malloc((size + 1) * sizeof(char));
	for (int i = 0; i < size + 1; i++) {
		location[i] = '\0';
	}	
	return location;
}
