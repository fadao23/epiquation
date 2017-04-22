//erreur.c

# ifndef _EPIQUATION_ERREUR_H_
# define _EPIQUATION_ERREUR_H_

# include <stdlib.h>
# include <stdio.h>

int *get_erreur(void);

void set_erreur(int x);

char *get_string_erreur(int erreur);

void free_erreur();

# endif /*_EPIQUATION_ERREUR_H_*/
