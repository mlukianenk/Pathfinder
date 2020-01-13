#include "pathfinder.h"

int main(int argc, char *argv[]) {
		
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
	t_form *info = mx_init (argc, argv);
	mx_all_functions(argv, info);
	return 0;
}
