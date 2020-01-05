#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx/inc/libmx.h"

typedef struct s_form {
    int islands; //the amount of islands
    char **lines;
} t_form;

void mx_printerr(char *filename);
bool mx_isaplha(int c);
bool mx_isdigit(int c);

bool mx_file_exist(char *filename);
bool mx_empty_file(char *filename);
bool mx_invalid_line(const char *file);

char **mx_file_info(t_form *info, const char *file);
#endif
