#include "pathfinder.h"

void mx_printerr(char *filename) {
    write(2, filename, mx_strlen(filename));
}

bool mx_isalpha(int c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;
    return false;
}

bool mx_isdigit(int c) {
    if (c >= 48 && c <= 57)
        return true;
    return false;
}
//function checks does the file exist

bool mx_file_exist(char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd > 0)
        return 1;
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    close(fd);

    return 0;
}

//function checks is file empty or not

bool mx_empty_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    char buff;
    int len = read(fd, &buff, 1);

    if (len > 0)
        return 1;
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" is empty\n");
    close(fd);
    exit(0);


}

//function checks the 1 line that must contain only digits

bool mx_invalid_line(const char *file) {
    char *lines = mx_file_to_str(file);

    for (int i = 0; lines[i] != '\n'; i++) {
        if (!(mx_isdigit(lines[i]))) {
            mx_printerr("error: line 1 is not valid \n");
            exit(0);
        }
    }
    return 1;
}

//writes information from the file into lines

char **mx_file_info(t_form *info, const char *file) {
    char *file_lines = mx_file_to_str(file);

    info->lines = mx_strsplit(file_lines, '\n');
    //for (int i = 0; info->lines[i]; i++) //цикл проверяющий все ли записалось в массив
    //    printf("%s\n", info->lines[i]);
    return NULL;
}

//checks the lines 

//не правильно выводит номер ошибки, всегда выводит 2

void mx_printerr_line(int number) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(number));
    mx_printerr(" is not valid\n");
   // return 0;
}

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

bool mx_invalid_lines(t_form *info) {
    for (int i = 1; info->lines[i]; i++) {
        int j = 0;

        while (info->lines[i][j] != '-' && info->lines[i]) {
            if (!(mx_isalpha(info->lines[i][j]))) {
                mx_printerr_line(i + 1);
                return 0;
            }
            j++;
        }
        j++;
        while (info->lines[i][j] != ',' && info->lines[i]) {
            if (!(mx_isalpha(info->lines[i][j]))) {
                mx_printerr_line(i + 1);
                return 0;    
            }
            j++;
        }
        j++;
        if (!(mx_invalid_digit(info, i, j))) {
            // mx_printerr_line(i + 1);
            return 0;
        }
    }
    return 1;
}
