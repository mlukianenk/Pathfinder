#include "pathfinder.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		mx_printstr("usage: ./pathfinder [filename]");
		exit(1);
	}
	mx_file_exist(argv[1]);
	return 0;
}
