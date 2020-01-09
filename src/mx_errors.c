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

int mx_atoi(const char *str) {
    int sign = 0;
    int sum = 0;

    for (; mx_isspace(*str); ++str);

    if (*str == '+' || *str == '-')
        sign = *str++ == '-';

    while (*str && mx_isdigit(*str))
        sum = sum * 10 + *str++ - 48;

    return sign ? -sum : sum;
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

//writes information from the file into lines

// char **mx_file_info(t_form *info, const char *file) {
//     char *file_lines = mx_file_to_str(file);

//     info->lines = mx_strsplit(file_lines, '\n');
//     // for (int i = 0; info->lines[i]; i++) //цикл проверяющий все ли записалось в массив
//     //    printf("%s\n", info->lines[i]);
//     return NULL;
// }

bool mx_file_info(t_form *info, const char *file) {
    char *file_lines = mx_file_to_str(file);
//int flag = 0;

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
    // for (int i = 0; info->lines[i]; i++) //цикл проверяющий все ли записалось в массив
    //    printf("%s\n", info->lines[i]);
    return NULL;
}


//function checks the 1st line that must contain only digits

bool mx_invalid_first(t_form *info) {
    for (int i = 0; info->lines[0][i] != '\0'; i++) {
        if (!(mx_isdigit(info->lines[0][i]))) {
            mx_printerr("error: line 1 is not valid \n");
            exit(0);
        }
    }
    if (mx_atoi(info->lines[0]) > 2147483647 || mx_atoi(info->lines[0]) < 1) {
        mx_printerr("error: line 1 is not valid \n");
        exit(0);
    }
    else
        info->islands = mx_atoi(info->lines[0]);
    return 1;
}

//checks the lines 

void mx_printerr_line(int number) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(number));
    mx_printerr(" is not valid\n");
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
                exit(0);
            }
            j++;
        }
        j++;
        while (info->lines[i][j] != ',' && info->lines[i]) {
            if (!(mx_isalpha(info->lines[i][j]))) {
                mx_printerr_line(i + 1);
                exit(0);    
            }
            j++;
        }
        j++;
        if (!(mx_invalid_digit(info, i, j))) {
            exit(0);
        }
    }
    return 1;
}

//writes information about islands from the file

int mx_multiarr_len(char **all_islands) {
    int len = 0;

    for (int i = 1; all_islands[i]; i++) {
        len += mx_strlen(all_islands[i]);
        len++;
    }
    return len;
}

int mx_multilen_no_zero(char **all_islands) {
    int len = 0;

    for (int i = 0; all_islands[i]; i++) {
        if (!(mx_strcmp(all_islands[i], "0") == 0))
            len++;
    }
    return len;
}

void mx_exclusive_islands(t_form *info) {

    char *all_lines = NULL;
   
    for (int i = 1; info->lines[i]; i++) {
        for (int j = 0; info->lines[i][j]; j++) {
            if (info->lines[i][j] == ',') 
                info->lines[i][j] = '\0';
        }
    }

    if (!(all_lines = mx_strnew(mx_multiarr_len(info->lines))))
        return;
    for (int i = 1, k = 0; info->lines[i]; i++) {
        if (i > 1)
            all_lines[k++] = '-';
        for (int j = 0; info->lines[i][j]; j++, k++) {
            all_lines[k] = info->lines[i][j];
        }
    }
    info->islands_names = mx_find_exclusive_islands(all_lines);
    // return NULL;
    // for (int i = 0; no_repeats[i];i++)
    //     printf("%s\n", no_repeats[i]);
}

char *mx_write_zero(char *str) {
    char *write_zero = mx_strnew(1);

    write_zero = mx_strcpy(write_zero, "0");
    mx_strdel(&str);
    return write_zero;
}

char **mx_find_exclusive_islands(char *all_lines) {
    char **w_repeats = NULL;
    char **no_repeats = NULL;
    int i = 0; //будет идти по строкам w_repeats
    int k = 0; //будет идти по строкам no_repeats

    w_repeats = mx_strsplit(all_lines, '-');
    mx_strdel(&all_lines);
    for (int i = 0; w_repeats[i]; i++) {
        for (int j = 0; w_repeats[j]; j++) {
            if ((i != j) && (mx_strcmp(w_repeats[i], w_repeats[j]) == 0))
                w_repeats[j] = mx_write_zero(w_repeats[j]);
        }
    }
    no_repeats = (char **) malloc(sizeof(*no_repeats) * (mx_multilen_no_zero(w_repeats) + 1));  
    while (w_repeats[i]) {
        if (mx_strcmp(w_repeats[i], "0") == 0)
            i++;
        else
            no_repeats[k++] = mx_strdup(w_repeats[i++]);
    }
    no_repeats[k] = NULL;
    mx_del_strarr(&w_repeats);
    return no_repeats;
}

//function that checks is there correct amount of islands in the file

bool mx_invalid_amount(t_form *info) {
    int count = 0;
    
    for (int i = 0; info->islands_names[i]; i++) {
        count++;   
    }
    if (count != info->islands) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    return 1;
}
