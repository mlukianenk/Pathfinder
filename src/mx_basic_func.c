#include "pathfinder.h"

void mx_printerr(char *filename) {
	write(2, filename, mx_strlen(filename));
}

void mx_printerr_line(int number) {
	mx_printerr("error: line ");
	mx_printerr(mx_itoa(number));
	mx_printerr(" is not valid\n");
}

bool mx_isalpha(int c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return true;
	return false;
}

bool mx_isdigit(int c) {
	if (c >= 48 && c <= 57)
		return true;
	return false;
}

int mx_atoi(const char *str) {
	int sign = 0;
	int sum = 0;

	for (; mx_isspace(*str); ++str) {
		if (*str == '+' || *str == '-')
			sign = *str++ == '-';
	}
	while (*str && mx_isdigit(*str))
		sum = sum * 10 + *str++ - 48;
	return sign ? -sum : sum;
}
