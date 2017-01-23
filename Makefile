# Makefile
 
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O0 -g3
LDFLAGS=
LDLIBS=
 
SRC=
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}
 
all:main
 
-include ${DEP}
 
main: ${OBJ}
 
clean:
	rm -f ${OBJ} ${DEP} main
 
# END
