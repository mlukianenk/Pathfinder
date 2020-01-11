#include "pathfinder.h"

//writes information about islands from the file

//counts len of multiarr
int mx_multiarr_len(char **all_islands) {
    int len = 0;

    for (int i = 1; all_islands[i]; i++) {
        len += mx_strlen(all_islands[i]);
        len++;
    }
    return len;
}

//counts without arrs with "0"
int mx_multilen_no_zero(char **all_islands) {
    int len = 0;

    for (int i = 0; all_islands[i]; i++) {
        if (!(mx_strcmp(all_islands[i], "0") == 0))
            len++;
    }
    return len;
}

//writes "0" instead of the string
char *mx_write_zero(char *str) {
    char *write_zero = mx_strnew(1);

    write_zero = mx_strcpy(write_zero, "0");
    mx_strdel(&str);
    return write_zero;
}

//finds the names of the islands in my file
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
    // for (int i = 0; no_repeats[i];i++)
    //     printf("%s\n", no_repeats[i]);
}

//deleats repeated names of islands and gives back the multiarr with exclusive islands 
char **mx_find_exclusive_islands(char *all_lines) {
    char **w_repeats = NULL;
    char **no_repeats = NULL;
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

    for (int i = 0; w_repeats[i];) {
        if (mx_strcmp(w_repeats[i], "0") == 0)
            i++;
        else
            no_repeats[k++] = mx_strdup(w_repeats[i++]);
    }
    no_repeats[k] = NULL;
    mx_del_strarr(&w_repeats);
    return no_repeats;
}
