#include "pathfinder.h"

void mx_printerr(char *filename) {
    write(2, filename, mx_strlen(filename));
}

bool mx_file_exist(char *filename) {
    int fd = open(filename, O_RDONLY);
    char buff; // здесь была строка, а тебе надо чтобы был символ, ибо ты считываешь по одному символу
    int len = read(fd, &buff, 1); // а здесь передать не просто buff, а &buff, то есть ссылку на адресс

    if (len > 0)
        return 1;
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");

    close(fd);

    return 0;
}
