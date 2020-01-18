#include "pathfinder.h" 

//function checks the distant between islands to be under max int

bool mx_invalid_max_distance(t_form *info) {
	int j = 0;

	for (int i = 1; info->lines[i]; i++) {
		j = mx_get_char_index(info->lines[i], ',') + 1;
		if (mx_strlen(&info->lines[i][j]) > 9) {
			mx_printerr_line(i + 1);
			exit(0);
		}
		if (mx_atoi(&info->lines[i][j]) == 0) {
			mx_printerr_line(i + 1);
			exit(0);
		}
	}
	return 1;
}

//function that checks lines

static int invalid_island1(t_form *info, int i, int j) {
	while (info->lines[i][j] != '-' && info->lines[i]) {
		if (!(mx_isalpha(info->lines[i][j]))) {
			mx_printerr_line(i + 1);
			exit(0);
		}
		j++;
	}
	return j;
}

static int invalid_island2(t_form *info, int i, int j) {
	while (info->lines[i][j] != ',' && info->lines[i]) {
		if (!(mx_isalpha(info->lines[i][j]))) {
			mx_printerr_line(i + 1);
			exit(0);
		}
		j++;
	}
	return j;
}

static bool invalid_distance(t_form *info, int i, int j) {
	while (info->lines[i][j]) {
		if (!(info->lines[i][j] >= '0' && info->lines[i][j] <= '9')) {
				mx_printerr_line(i + 1);
				exit(0);
		}
		j++;
	}
	return 1;
}

bool mx_invalid_lines(t_form *info) {
	for (int i = 1, j; info->lines[i]; i++) {
		j = 0;
		j = invalid_island1(info, i, j);
		j++;
		j = invalid_island2(info, i, j);
		j++;
		if (!(invalid_distance(info, i, j)))
			exit(0);
	}
	return 1;
}
