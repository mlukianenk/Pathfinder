#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx/inc/libmx.h"

typedef struct s_form {
    int islands;
    char **line_file;
} t_form;

void mx_printerr(char *filename);
bool mx_isaplha(int c);

bool mx_file_exist(char *filename);
bool mx_empty_file(char *filename);
bool mx_invalid_line(const char *file);

#endif
