#include "pathfinder.h"

t_form *mx_init(int argc, char **argv) {
    t_form *info = (t_form *)malloc(sizeof(t_form)); // тут правильно
    info->islands = 0;
	info->lines = NULL;
	info->all_lines = NULL;
	info->islands_names = NULL; 
    info->matrix = NULL;   

    (void)argc;
    (void)argv;
    return info;
}
