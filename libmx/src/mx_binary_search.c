#include "libmx.h"
#include <stdio.h>
int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int min = 0;
	int max = size - 1;
	int mid;
	*count = 0;
	
	while (min <= max) {
		*count += 1;
		mid = (min + max) / 2;
		if (mx_strcmp(s, arr[mid]) < 0) {
			max = mid - 1;
		}
		else if (mx_strcmp(s, arr[mid]) > 0) {
			min = mid + 1;
		}
		else {
			return mid;
		}
	}
	*count = 0;
	return -1;
}
