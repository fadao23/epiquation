//Calcul of values in binary tree

# ifndef _EPIQUATION_CALCUL_H_
# define _EPIQUATION_CALCUL_H_

# include <stdlib.h>

# include "../tree/function.h"
# include "../tree/operator.h"
# include "../tree/tree.h"

/*
**  multiplie_tree: make distribute the number  in factor
**  in function example : 4(ax + b) = 4*ax + 4*b
**  After, the function remove children which had the number
*/
void multiplie_tree(struct s_tree *node, float coef);

# endif /* _EPIQUATION_CALCUL_H_ */
