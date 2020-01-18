#include "pathfinder.h"

void mx_algorithm(t_form *info) {
    int new_distance = 0;

    // printf("\n");
    // for (int i = 0; i < info->islands; i++) {
    //     for (int j = 0; j < info->islands; j++)
    //         printf("[%d]\t", info->matrix[i][j]);
    //     printf("\n");
    // }

    for (int k = 0; k < info->islands; k++) {
        for (int i = 0; i < info->islands; i++) {
            for (int j = 0; j < info->islands; j++) {
                new_distance = info->matrix[i][k] + info->matrix[k][j];
                if (new_distance < info->matrix[i][j])
                    info->matrix[i][j] = new_distance;
            }
        }
    }
//      printf("\n");
//     for (int i = 0; i < info->islands; i++) {
//         for (int j = 0; j < info->islands; j++)
//             printf("[%d]\t", info->matrix[i][j]);
//         printf("\n");
//     }
// exit(0);
        // for (int i = 0; i < info->islands; i++) 
        //         mx_printstr(info->islands_names[i]);
//         // for (int j = 0; j < info->islands; j++)
//             printf("[%s]\t", info->islands_names[i]);
//         printf("\n");
//     }
}
