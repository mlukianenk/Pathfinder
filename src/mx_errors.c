#include "pathfinder.h"

void mx_printerr(char *filename) {
    write(2, filename, mx_strlen(filename));
}

bool mx_isalpha(int c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return true;
    }
    return false;
}

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
    return 0;
    //посмотри на функцию ниже и подумай, что ты сделала там так,
    //чтобы оно отрабатывала правильно, а эта и ф-ция выше нет
}

bool mx_invalid_line(const char *file) {
    char *lines = mx_file_to_str(file);

    while(*lines !='\n') {
        for (int i = 0; lines[i]; i++) {
            if (!(mx_isalpha(lines[i]))) {
                mx_printerr("error: line 1 is not valid \n");
                exit(0);
            }
        }
    }
    return 1;
}

// закоментил, чтобы работало, допиши эту функцию 

// bool mx_invalid_lines(const char *file) {
//     char *lines = mx_file_to_str(file); 

// }
