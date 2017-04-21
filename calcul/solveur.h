//solveur.h list some function useful to solve an equation

# ifndef _EPIQUATION_SOLVEUR_H_
# define _EPIQUATION_SOLVEUR_H_

# include <stdlib.h>

# include "list.h"
# include "simplify.h"

# include "../tree/function.h"
# include "../tree/operator.h"
# include "../tree/tree.h"
# include "../tree/variable.h"

/*
**	has_variable: check if a tree contain a variable
**		tree: tree to check
**	has_variable check if [tree] is null, in this case return. If [tree] is a
**	variable return 1 otherwise call recursively the function on each children
*/
int has_variable(struct s_tree *tree);

int _get_list(struct s_tree *node, struct s_list *list, int val);

float solveur(struct s_tree *tree, float res, int egal);

void change(struct s_list *from, struct s_list *to);

float calc_no_var(struct s_tree *node);

float calc_res(struct s_list *l, float egal, int type);
# endif /*_EPIQUATION_SOLVEUR_H_*/
