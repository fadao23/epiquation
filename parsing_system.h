//parsing_system.h contains function to parse linear system

# ifndef _EPIQUATION_PARSING_SYSTEM_H_
# define _EPIQUATION_PARSING_SYSTEM_H_

# include <sys/types.h>
# include <regex.h>
# include <err.h>
# include <stdlib.h>
# include <stdio.h>


void **parsing_sys(char **system, int n);
int get_rang(char *vs, int n, char v);
int get_next(char *s, int *i, char *v);
char *clean(char *s, int max);
int comp_regex(char *string, char *reg);

# endif /* _EPIQUATION_PARSING_SYSTEM_H_*/
