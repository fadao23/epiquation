// control.h

# ifndef _EPIQUATION_CONTROL_H_
# define _EPIQUATION_CONTROL_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "erreur.h"
# include "../calcul/crout.h"
# include "../parsing/parsing.h"

char *solve_system(char ** system,int n);

# endif  /*_EPIQUATION_CONTROL_H_*/

