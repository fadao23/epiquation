# Makefile
 
CC=gcc -fsanitize=address
#CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g3
LDFLAGS=
LDLIBS= -lm
 
SRC= main.c function.c variable.c tree.c parsing.c operator.c\
list.c build.c simplify.c solveur.c calcul.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}
 
all:main
 
-include ${DEP}
 
main: ${OBJ}
 
clean:
	rm -f ${OBJ} ${DEP} main
 
# END
