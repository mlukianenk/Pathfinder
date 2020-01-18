#include "pathfinder.h"

void mx_del_int_arr(int **arr, int size) {
	int i = -1;

	while (++i < size) {
		free(arr[i]);
	}
	free(arr);
}

//counts len of multiarr

int mx_multiarr_len(char **all_islands) {
	int len = 0;

	for (int i = 1; all_islands[i]; i++) {
		len += mx_strlen(all_islands[i]);
		len++;
	}
	return len;
}

//counts without arrs with "0"

int mx_multilen_no_zero(char **all_islands) {
	int len = 0;

	for (int i = 0; all_islands[i]; i++) {
		if (!(mx_strcmp(all_islands[i], "0") == 0))
			len++;
	}
	return len;
}

