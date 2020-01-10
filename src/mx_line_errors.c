#include "pathfinder.h" 

//function checks the distant between islands to be under max int

bool mx_invalid_distance(t_form *info) {
    int j = 0;

    for (int i = 1; info->lines[i]; i++) {
        j = mx_get_char_index(info->lines[i], ',') + 1; //чтобы иметь индекс не ',' а 1 цифры
        if (mx_strlen(&info->lines[i][j]) > 9) {
            mx_printerr_line(i + 1);
            exit(0);
        }
        if (mx_atoi(&info->lines[i][j]) == 0) {
            mx_printerr_line(i + 1);
            exit(0);
        }
    } 
    return 1;
}

//function checks the 1st line that must contain only digits

bool mx_invalid_first(t_form *info) {
    for (int i = 0; info->lines[0][i] != '\0'; i++) {
        if (!(mx_isdigit(info->lines[0][i]))) {
            mx_printerr("error: line 1 is not valid \n");
            exit(0);
        }
    }
    if (mx_atoi(info->lines[0]) > 2147483647 || mx_atoi(info->lines[0]) < 1) {
        mx_printerr("error: line 1 is not valid \n");
        exit(0);
    }
    else
        info->islands = mx_atoi(info->lines[0]);
    return 1;
}

//function that checks lines 

bool mx_invalid_lines(t_form *info) {
    for (int i = 1; info->lines[i]; i++) {
        int j = 0;

        while (info->lines[i][j] != '-' && info->lines[i]) {
            if (!(mx_isalpha(info->lines[i][j]))) {
                mx_printerr_line(i + 1);
                exit(0);
            }
            j++;
        }
        j++;
        while (info->lines[i][j] != ',' && info->lines[i]) {
            if (!(mx_isalpha(info->lines[i][j]))) {
                mx_printerr_line(i + 1);
                exit(0);    
            }
            j++;
        }
        j++;
        if (!(mx_invalid_digit(info, i, j))) {
            exit(0);
        }
    }
    return 1;
}

//function that checks distant to be a digit

bool mx_invalid_digit(t_form *info, int i, int j) {
    while (info->lines[i][j]) {
        if (!(info->lines[i][j] >= '0' && info->lines[i][j] <= '9')) {
                mx_printerr_line(i + 1);
                exit(0);
        }
        j++;
    }
    return 1;
}
