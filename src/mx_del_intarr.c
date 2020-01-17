#include "pathfinder.h"

static void mx_intdel(int **num) {
    free(*num);
}

void mx_del_intarr(int ***arr) {
    int **del_arr = *arr;

    while(*del_arr) {
        mx_intdel(del_arr++);
    }
    free(*arr);
}
