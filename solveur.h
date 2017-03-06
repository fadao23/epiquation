//solveur.h list some function useful to solve an equation

# ifndef _EPIQUATION_SOLVEUR_H_
# define _EPIQUATION_SOLVEUR_H_

# include <stdlib.h>

# include "tree.h"
# include "operator.h"
# include "function.h"

int has_variable(struct s_tree *tree);

float solveur(struct s_tree *tree);

struct s_tree *_solveur(struct s_tree *tree);

void attache(struct s_tree **node, struct s_tree *value, enum e_operator
*oper);

# endif /*_EPIQUATION_SOLVEUR_H_*/
