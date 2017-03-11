//List of function used to simplify a tree

# ifndef _EPIQUATION_SIMPLIFY_H_
# define _EPIQUATION_SIMPLIFY_H_

# include <stdlib.h>

# include "function.h"
# include "variable.h"
# include "tree.h"

/*
**	simplify_plus: simplifies a tree by doing plus operation
**		node: the current node in the tree
**		tmp: a pointer used to raise a node
**	simplify_plus get the type of [node]
**		If it's a value, return the value.
**		If it's not a plus operator return 0
**		Else call simplify_plus on the two children. if all children return is
**			0, return 0 else if all call to children node have a not null tmp,
**			create a plus operator node with it's children set to the two tmp and
**			put this node in [tmp]. if they are only one children with tmp not
**			null put it in [tmp], after that return the sum of the two children's
**			return.
*/
void simplify_plus(struct s_tree *node, struct s_list *list, float coef, int krisbool);

/*
**	simplify_minus: remove all minus node
**		node: the current node in the tree
**		coef: the multiplier (must be egal to -1 or 1)
**	simplify_minus get the type of [node]
**		If it's a value, multiply value by coef
**		If it's a function or a variable, multiply coef by [node]'s coef
**		If it's a minus operator, change [node] operator to plus and call
**			simplify_minus with [coef] * -1 on each children
**		If it's another operator, call simplify_minus with [coef] on each children
*/
void simplify_minus(struct s_tree *node, int coef);




struct s_tree rebuild_tree(struct s_list *list, float coef);

/*
**	simplify_mult: simplifies a tree by doing time operation
**		node: The current node in the tree
**		list: List where everything but values are put into if krisbool = 1
**		coef: The multiplier (must be at 1 by default)
**		krisbool: Boolean to know if a '*' has already been passed
*/
void simplify_mult(struct s_tree *node, struct s_list *list, float coef, int krisbool);

# endif /* _EPIQUATION_SIMPLIFY_H_ */
