#include "pathfinder.h"

void mx_output_format(t_form *info, t_path *path) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_print_start(info, path);
    mx_printstr("Route: ");
    mx_print_route(info, path);
    mx_printstr("Distance: ");
    mx_print_dist(info, path);
    mx_printstr("\n");
    mx_printstr("========================================\n");
}

void mx_print_start(t_form *info, t_path *path) {
    mx_printstr(info->islands_names[path->path[1]]);
    mx_printstr(" -> ");
    mx_printstr(info->islands_names[path->path[0]]);
    mx_printstr("\n");
}

void mx_print_route(t_form *info, t_path *path) {
    for (int i = 1; i <= path->size; i++) {
        mx_printstr(info->islands_names[path->path[i]]);
        if (i < path->size)
            mx_printstr(" -> ");
        else
            mx_printstr("\n");
    }
}

void mx_print_dist(t_form *info, t_path *path) {
    int sum = 0;
    int n = path->size;

    if (n == 2)
        mx_printint(info->matrix[path->path[n]][path->path[n - 1]]);
    else {
        for (int i = 1; i < n; i++) {
            mx_printint(info->matrix[path->path[i]][path->path[i + 1]]);
            sum += info->matrix[path->path[i]][path->path[i + 1]];
            if (i + 1 < n) {
                mx_printstr(" + ");
            }
            else {
                mx_printstr(" = ");
                mx_printint(sum);
            }
        }
        // mx_printstr("\n");
    }
}
