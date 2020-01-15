#include "pathfinder.h"

t_form *mx_init(int argc, char **argv) {
    t_form *info = (t_form *)malloc(sizeof(t_form)); // тут правильно
    info->islands = 0;
	info->lines = NULL;
	info->all_lines = NULL;
	info->islands_names = NULL;
    info->file_matrix = NULL;
    info->matrix = NULL;   

    (void)argc;
    (void)argv;
    return info;
}

static int* mem_int_arr(int count) {
    int *arr = (int *)malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++) {
        arr[i] = 0;
    }
    return arr;
}

t_path *mx_init_path(t_form *info, int start, int end) {
    t_path *path = (t_path *)malloc(sizeof(t_path));

    path->path = mem_int_arr(info->islands);
    path->count = info->islands;
    path->size = 1;
    path->path[0] = end;
    path->path[1] = start;
    return path;
}
