#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx/inc/libmx.h"

typedef struct s_form {
    int islands; //the amount of islands
    char **lines; 
    char **islands_names; //all islands
} t_form;

void mx_printerr(char *filename);
bool mx_isaplha(int c);
bool mx_isdigit(int c);
void mx_printerr_line(int number);
bool mx_invalid_digit(t_form *info, int i, int j);
bool mx_invalid_lines(t_form *info);

bool mx_file_exist(char *filename);
bool mx_empty_file(char *filename);
bool mx_invalid_line(const char *file);
char **mx_islands_info(t_form *info);

int mx_multiarr_len(char **all_islands);
int mx_multilen_no_zero(char **all_islands);
char **mx_exclusive_islands(t_form *info);
char *mx_write_zero(char *str);
char **mx_find_exclusive_islands(char *all_lines);

char **mx_file_info(t_form *info, const char *file);
#endif
