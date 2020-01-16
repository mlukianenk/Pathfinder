#include "pathfinder.h"

void mx_all_functions(char *argv[], t_form *info) {
	mx_file_exist(argv[1]);
	system("leaks pathfinder");
	mx_empty_file(argv[1]);
	mx_file_info(info, argv[1]);
	mx_invalid_distance(info);
	mx_invalid_first(info);	
	mx_invalid_lines(info);
	mx_exclusive_islands(info);
	mx_invalid_amount(info);
	mx_create_matrix(info);
	mx_algorithm(info);
	mx_all_output(info);
	mx_delete_liks(info);
	system("leaks pathfinder");
}

void mx_delete_liks(t_form *info) {
	mx_del_strarr(&info->lines);
	mx_del_strarr(&info->all_lines);
	mx_del_strarr(&info->islands_names);
	free(info);
}
