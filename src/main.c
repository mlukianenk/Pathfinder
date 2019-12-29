#include "pathfinder.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		/*
		** здесь тоже надо выводить все через printerr,
		** как и все ошибки в целом, а еще не забывай переводить на новую строчку
		*/
		mx_printstr("usage: ./pathfinder [filename]");
		exit(1);
	}
	mx_file_exist(argv[1]);
	return 0;
}
