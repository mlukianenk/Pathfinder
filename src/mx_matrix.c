#include "pathfinder.h"
int mx_get_num_from_str(char *line);
// int **mx_zero_matrix(int N) {
//     printf("123\n");
//     int **mass = (int **)malloc(sizeof(int *) * N);
//     printf("%d\n", N);
//     for (int i = 0; i < N; i++) {
//         mass[i] = (int *)malloc(sizeof(int) * N);
//         for (int j = 0; j < N; j++) {
//             mass[i][j] = 1000000;
//         }
//     }

//     for (int j = 0; j < N; j++) {
//             mass[j][j] = 0;
//         }
//     // int **mx_create_zero_mass(int N) {
// 	// int **mass = (int **)malloc(sizeof(int *) * N);

// 	// for (int i = 0; i < N; i++) {
// 	// 	mass[i] = (int *)malloc(sizeof(int) * N);
// 	// 	for (int j = 0; j < N; j++) {
// 	// 		mass[i][j] = 100000000;
// 	// 	}
// 	// }
// 	// for (int i = 0; i < N; i++) {
// 	// 	mass[i][i] = 0;
// 	// }
//     for (int i = 0; mass[i]; i++) {
//         for (int j = 0; mass[i][j]; j++)
//             printf("%d ", mass[i][j]);
//         printf("\n");
//     }
//     return mass;
// }

// int mx_get_digit_index(char *line) {
//     int pos = 0;

//     pos = mx_get_char_index(line, ',') + 1;
//     return mx_atoi(&line[pos]);
// }

// int **mx_create_matrix(t_form *info) {
//     printf("%d\n", info->islands);
//     int **mass = mx_zero_matrix(info->islands);
//     char *island_2 = NULL;

// //i двигается по строкам
// //j двигается по 1 слову
// //k двигается по 2 слову
//     for (int i = 1, j = 0, k = 0; info->all_lines[i]; i++) {

//         for (j = 0; j < info->islands; j++) {
//             if (mx_memcmp(info->all_lines[i], info->islands_names[j], mx_strlen(info->islands_names[j])) == 0) {
//                 break;
//             }
//         }
//         island_2 = mx_memchr(info->all_lines[i], '-', mx_strlen(info->all_lines[i]));
//         for (k = 0; k < info->islands; k++) {
//             if (mx_memcmp(island_2 + 1, info->islands_names[k], mx_strlen(info->islands_names[k])) == 0)
//                 break;
//         }
//         mass[j][k] = mx_get_digit_index(info->all_lines[i]);
//         mass[k][j] = mass[j][k];
//     }

//     for (int i = 0; mass[i]; i++) {
//         for (int j = 0; mass[i][j]; j++)
//             printf("%d ", mass[i][j]);
//         printf("\n");
//     }
//     return mass;
// }

int **mx_create_zero_mass(int N) {
	int **mass = (int **)malloc(sizeof(int *) * N);

	for (int i = 0; i < N; i++) {
		mass[i] = (int *)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			mass[i][j] = 100000000;
		}
	}
	for (int i = 0; i < N; i++) {
		mass[i][i] = 0;
	}
	return mass;
}

int **mx_create_mass(t_form *p_find) {
	int **mass = mx_create_zero_mass(p_find->islands);
	char *two = NULL;
	for (int line = 1, i = 0, j = 0; p_find->all_lines[line]; line++) {
        // printf("%s\n", p_find->islands_names[]);
		// mx_check_island_name(p_find->all_lines[line], line);
		for (i = 0; i < p_find->islands; i++) {
            if (mx_memcmp(p_find->all_lines[line], p_find->all_lines[i],
							 mx_strlen(p_find->islands_names[i])) == 0)
				break;
        }
		two = mx_memchr(p_find->all_lines[line], '-',
					mx_strlen(p_find->all_lines[line]));
		for (j = 0; j < p_find->islands; j++)
			if (mx_memcmp(two + 1, p_find->islands_names[j],
							mx_strlen(p_find->islands_names[j])) == 0)
				break;
		mass[i][j] = mx_get_num_from_str(p_find->all_lines[line]);
		mass[j][i] = mass[i][j];
	}
    for (int i = 0; mass[i]; i++) {
        for (int j = 0; mass[i][j]; j++)
            printf("%d ", mass[i][j]);
        printf("\n");
    }
	return mass;
}

int mx_get_num_from_str(char *line) {
	int position = mx_get_char_index(line, ',') + 1;

	return mx_atoi(&line[position]);
}
