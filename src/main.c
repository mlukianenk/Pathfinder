#include "pathfinder.h"

int main(int argc, char *argv[]) {
		
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
	t_form *info = (t_form *)malloc(sizeof(t_form)); // тут правильно
	info->islands = 0;
	info->lines = NULL;
	info->islands_names = NULL;

	mx_file_exist(argv[1]);
	mx_empty_file(argv[1]);
	mx_file_info(info, argv[1]);
	mx_invalid_first(info);
	mx_invalid_lines(info);
	mx_exclusive_islands(info);
	mx_invalid_amount(info);
	return 0;
}
