#include "libmx.h"

static int get_len_num(int number);

char *mx_itoa(int number) {
	int len = get_len_num(number);
	char *int_to_str = NULL;
	
	if ((number != 0) && (number != -2147483648)) {
		if (number < 0)
			int_to_str = mx_strnew(len + 1);
		else
			int_to_str = mx_strnew(len);
		for (int i = 0; i < len; i++) {
			if (number < 0) {
				int_to_str[len] = '-';
				number *= -1;
			}
			int_to_str[i] = (number % 10) + 48;
			number /= 10;
		}
		mx_str_reverse(int_to_str);
		return int_to_str;
	}
	return (number == 0) ? mx_strdup("0") : mx_strdup("-2147483648");
}

static int get_len_num(int number) {
	int len = 0;
	int copy_num = number;

	while(copy_num) {
		copy_num /= 10;
		len++;
	}
	return len;
}
