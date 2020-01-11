#include "pathfinder.h"

void mx_all_functions(char *argv[], t_form *info) {
	mx_file_exist(argv[1]);
	mx_empty_file(argv[1]);
	mx_file_info(info, argv[1]);
	mx_invalid_distance(info);
	mx_invalid_first(info);
	mx_invalid_lines(info);
	mx_exclusive_islands(info);
	mx_invalid_amount(info);
	mx_create_mass(info);
}
