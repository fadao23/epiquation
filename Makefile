# Makefile

CC=gcc -fsanitize=address
#CC=gcc
CPPFLAGS=`pkg-config --cflags gtk+-3.0` -export-dynamic
CFLAGS= -Wall -Wextra -std=c99 -O0 -g3
LDFLAGS=
LDLIBS=`pkg-config --libs gtk+-3.0` `pkg-config --libs sdl`  -lSDL_image -export-dynamic  -lm

SRC= \
	main.c \
	tree/build.c tree/function.c tree/operator.c tree/test_tree.c \
	tree/tree.c tree/variable.c \
	parsing/pars_equat.c parsing/pars_syste.c parsing/trt_string.c \
	controller/erreur.c controller/control.c \
	calcul/calcul.c calcul/crout.c calcul/list.c calcul/simplify.c \
	calcul/solveur.c calcul/polynomes.c

OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all:main

-include ${DEP}

main: ${OBJ}

clean:
	rm -f ${OBJ}

clean_all:
	rm -f ${OBJ} ${DEP} main

# END
