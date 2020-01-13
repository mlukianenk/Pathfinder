#include "pathfinder.h"

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

//function checks is the file empty or not

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

//writes information from the file into lines

bool mx_file_info(t_form *info, const char *file) {
    char *file_lines = mx_file_to_str(file);

    for (int i = 0, j = 0; file_lines[i]; i++) {
        if (file_lines[i] == '\n'&& file_lines[i + 1] != '\n')
            j++;
        if (file_lines[i] == '\n' && file_lines[i + 1] == '\n') {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(j + 1));
            mx_printerr(" is not valid\n");
            exit(0);
        }
    }
    info->lines = mx_strsplit(file_lines, '\n');
    info->all_lines = mx_strsplit(file_lines, '\n');
    mx_strdel(&file_lines);
    // for (int i = 0; info->lines[i]; i++) //цикл проверяющий все ли записалось в массив
    //    printf("%s\n", info->lines[i]);
    return NULL;
}

//function that checks is there correct amount of islands in the file

bool mx_invalid_amount(t_form *info) {
    int count = 0;
    
    for (int i = 0; info->islands_names[i]; i++) {
        // printf("%d\n", count);
        count++;   
    }
    // printf("%d\n", count);
    if (count != info->islands) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    return 1;
}
