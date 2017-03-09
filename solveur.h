//solveur.h list some function useful to solve an equation

# ifndef _EPIQUATION_SOLVEUR_H_
# define _EPIQUATION_SOLVEUR_H_

# include <stdlib.h>

# include "simplify.h"
# include "list.h"
# include "tree.h"
# include "operator.h"
# include "function.h"
# include "variable.h"

/*
**	has_variable: check if a tree contain a variable
**		tree: tree to check
**	has_variable check if [tree] is null, in this case return. If [tree] is a
**	variable return 1 otherwise call recursively the function on each children
*/
int has_variable(struct s_tree *tree);

void _get_list(struct s_tree *node, struct s_list *list);

float solveur(struct s_tree *tree);

float calc_no_var(struct s_tree *node);

# endif /*_EPIQUATION_SOLVEUR_H_*/
