#include "pathfinder.h"

int **mx_zero_matrix(int N) {
    int **mass = (int **)malloc(sizeof(int *) * N);
    int i = 0;
    int j = 0;

    for (i = 0; i < N; i++) {
        mass[i] = (int *)malloc(sizeof(int) * N);
        for (j = 0; j < N; j++)
            mass[i][j] = 21474836;
    }
    for (int j = 0; j < N; j++)
            mass[j][j] = 0;
    return mass;
}

int mx_get_digit_index(char *line) {
    int pos = 0;

    pos = mx_get_char_index(line, ',') + 1;
    return mx_atoi(&line[pos]);
}

static void fill_mass(t_form *info, int **mass, int i, int j) {
    int k = 0;
    char *island_2 = NULL;

    island_2 = mx_memchr(info->all_lines[i], '-',
    mx_strlen(info->all_lines[i]));
    for (k = 0; k < info->islands; k++) {
        if (mx_memcmp(island_2 + 1, info->islands_names[k],
            mx_strlen(info->islands_names[k])) == 0) {
            break;
        }
    }
    mass[j][k] = mx_get_digit_index(info->all_lines[i]);
    mass[k][j] = mass[j][k];
}

int **mx_create_matrix(t_form *info) {
    int **mass = mx_zero_matrix(info->islands);

    for (int i = 1, j = 0; info->all_lines[i]; i++) {
        for (j = 0; j < info->islands; j++) {
            if (mx_memcmp(info->all_lines[i], info->islands_names[j],
                mx_strlen(info->islands_names[j])) == 0) {
                break;
            }
        }
        fill_mass(info, mass, i, j);
    }
    // info->matrix = mass;
    info->file_matrix = (int**)malloc(sizeof(int*) * info->islands);
    for (int i = 0; i < info->islands; i++) {
        info->file_matrix[i] = (int*)malloc(sizeof(int) * info->islands);
        for(int j = 0; j < info->islands; j++)
            info->file_matrix[i][j] = mass[i][j];
    }
    info->matrix = mass;
    //  printf("\n");
    // for (int i = 0; i < info->islands; i++) {
    //     for (int j = 0; j < info->islands; j++)
    //         printf("[%d]\t", info->matrix[i][j]);
    //     printf("\n");
    // }
    return mass;
}
