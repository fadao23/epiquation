# Makefile

CC=gcc # -fsanitize=address
#CC=gcc
CPPFLAGS=`pkg-config --cflags gtk+-3.0` -export-dynamic
CFLAGS= -Wall -Wextra -std=c99 -O0 -g3
LDFLAGS=
LDLIBS=`pkg-config --libs gtk+-3.0` `pkg-config --libs sdl`  -lSDL_image -export-dynamic  -lm

SRC= main.c function.c variable.c tree.c parsing.c operator.c\
list.c build.c simplify.c solveur.c calcul.c test_tree.c erreur.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all:main

-include ${DEP}

main: ${OBJ}

clean:
	rm -f ${OBJ} ${DEP} main

# END
