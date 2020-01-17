#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx/inc/libmx.h"

typedef struct s_form {
    int islands; //the amount of islands
    char **lines;
    char **all_lines; //multiarr reserv with all lines
    char **islands_names; //all islands
    int **file_matrix; //matrix from file
    int **matrix; //matrix with distance between islands
} t_form;

typedef struct s_path {
    int *path;
    int count;
    int size;
} t_path;

void mx_all_functions(char *argv[], t_form *info); //main.c
void mx_delete_liks(t_form *info); //mx_all_functions.c

//mx_init.c
t_form *mx_init(int argc, char **argv);
t_path *mx_init_path(t_form *info, int start, int end);

//mx_basic_func.c
bool mx_isalpha(int c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
void mx_printerr(char *filename);
void mx_printerr_line(int number);

//mx_islands_info.c

char *mx_write_zero(char *str);
int mx_multiarr_len(char **all_islands);
char **mx_exclusive_islands(t_form *info);
int mx_multilen_no_zero(char **all_islands);
char **mx_find_exclusive_islands(char *all_lines);

//mx_file_errors.c
bool mx_file_exist(char *filename);
bool mx_empty_file(char *filename);
bool mx_invalid_amount(t_form *info);
bool mx_file_info(t_form *info, const char *file);

//mx_line_errors.c
bool mx_invalid_lines(t_form *info);
bool mx_invalid_max_distance(t_form *info);
bool mx_invalid_first(t_form *info);

//mx_matrix.c
int **mx_create_zero_mass(int N);
int **mx_zero_matrix(int N);
int mx_get_digit_index(char *line);
int **mx_create_matrix(t_form *info);

//mx_algorithm.c
void mx_algorithm(t_form *info);

//mx_output.c
void mx_all_output(t_form *info);
void mx_output(t_form *info, int start, int end);
void mx_backtrack(t_form *info, t_path *path);
int mx_check_path(int n, t_form *info, t_path *path);
 
//mx_output_all.c
void mx_output_format(t_form *info, t_path *path);
void mx_print_start(t_form *info, t_path *path);
void mx_print_route(t_form *info, t_path *path);
void mx_print_dist(t_form *info, t_path *path);

void mx_del_intarr(int ***arr);

#endif
