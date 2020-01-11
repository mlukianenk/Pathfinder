#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx/inc/libmx.h"

typedef struct s_form {
    int islands; //the amount of islands
    char **lines;
    char **all_lines; //multiarr reserv with all lines
    char **islands_names; //all islands
} t_form;

void mx_all_functions(char *argv[], t_form *info); //main.c
t_form *mx_init(int argc, char **argv); //mx_init.c

//mx_basic_func.c
bool mx_isalpha(int c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
void mx_printerr(char *filename);
void mx_printerr_line(int number);

//mx_islands_info.c

char *mx_write_zero(char *str);
int mx_multiarr_len(char **all_islands);
void mx_exclusive_islands(t_form *info);
int mx_multilen_no_zero(char **all_islands);
char **mx_find_exclusive_islands(char *all_lines);

//mx_file_errors.c
bool mx_file_exist(char *filename);
bool mx_empty_file(char *filename);
bool mx_invalid_amount(t_form *info);
bool mx_file_info(t_form *info, const char *file);

//mx_line_errors.c
bool mx_invalid_digit(t_form *info, int i, int j);
bool mx_invalid_lines(t_form *info);
bool mx_invalid_distance(t_form *info);
bool mx_invalid_first(t_form *info);

// char **mx_islands_info(t_form *info);

#endif
