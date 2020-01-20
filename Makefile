NAME = pathfinder

INC = pathfinder.h

SRC = main.c \
mx_algorithm.c \
mx_all_functions.c \
mx_basic_func.c \
mx_basic_func_2.c \
mx_file_errors.c \
mx_init.c \
mx_islands_info.c \
mx_line_errors.c \
mx_matrix.c \
mx_output.c \
mx_output_all.c

OBJ = main.o \
mx_algorithm.o \
mx_all_functions.o \
mx_basic_func.o \
mx_basic_func_2.o \
mx_file_errors.o \
mx_init.o \
mx_islands_info.o \
mx_line_errors.o \
mx_matrix.o \
mx_output.o \
mx_output_all.o

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install

install:
	@make -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj

reinstall: uninstall install
