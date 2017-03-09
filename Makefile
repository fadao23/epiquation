# Makefile
 
CC=gcc -fsanitize=address
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g3
LDFLAGS=
LDLIBS= -lm
 
SRC= main.c function.c variable.c tree.c parsing.c operator.c test_tree.c\
list.c build.c simplify.c solveur.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}
 
all:main
 
-include ${DEP}
 
main: ${OBJ}
 
clean:
	rm -f ${OBJ} ${DEP} main
 
# END
