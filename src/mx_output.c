#include "pathfinder.h"

void mx_all_output(t_form *info) {
    for (int i = 0; i < info->islands; i++) {
        for (int j = 0; j < info->islands; j++) {
            if (i < j) {
                mx_output(info, i, j);
            }
        }
    }
}

void mx_output(t_form *info, int start, int end) {
    t_path *path = mx_init_path(info, start, end);

    mx_backtrack(info, path);
    free(path->path);
    free(path);
}

void mx_backtrack(t_form *info, t_path *path) {
    if (path->path[path->size] == path->path[0])
        mx_output_format(info, path);
    else {
        for (int i = 0; i < info->islands; i++) {
            if (mx_check_path(i, info, path)) {
                if (path->size < path->count) {
                    path->size++;
                    path->path[path->size] = i;
                }
                mx_backtrack(info, path);
                if (path->size > 1)
                    path->size--;
            }
        }
    }
}

int mx_check_path(int n, t_form *info, t_path *path) {
    int i = path->path[path->size];
    int j = path->path[0];

    if (i != n) {
        if (info->file_matrix[i][n] == info->matrix[j][i]
            - info->matrix[j][n]) {
            return 1;
        }
    }
    return 0;
}
