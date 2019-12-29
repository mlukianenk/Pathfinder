#include "pathfinder.h"

void mx_printerr(char *filename) {
    write(2, filename, mx_strlen(filename));
}

bool mx_file_exist(char *filename) {
    int fd = open(filename, O_RDONLY);
    char *buff;
    int len = read(fd, buff, 1);

    if (len > 0)
        return 1;
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr("does not exist\n");

    close(fd);

    return 0;
}
