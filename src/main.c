#include "pathfinder.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
	mx_file_exist(argv[1]);
	mx_empty_file(argv[1]);
	mx_invalid_line(argv[1]);
	
	return 0;
}
