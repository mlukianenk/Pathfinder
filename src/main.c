#include "pathfinder.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(0);
	}
	t_form *info = (t_form *)malloc(sizeof(t_form)); // тут правильно
	/*
		здесь надо все занулить:
		обращаешься к полю структуры и зануляешь каждую переменную
		пример info->(переменная из твоей структуры) = 0 или NULL
		зависит от типа переменной
	*/
	info->islands = 0;
	info->lines = NULL;

	mx_file_exist(argv[1]);
	mx_empty_file(argv[1]);
	//mx_invalid_line(argv[1]);
	// это вызов твоей функции, что обрабатывает файл
	mx_file_info(info, argv[1]);
	return 0;
}
