//test_tree.h list functions usefull to test a tree

# ifndef _EPIQUATION_TEST_TREE_H_
# define _EPIQUATION_TEST_TREE_H_

# include <stdio.h>

# include "function.h"
# include "operator.h"
# include "variable.h"
# include "tree.h"


char *tree_to_string(struct s_tree *tree);

void _tree_to_string(struct s_tree *tree, char *rep);

void function_to_string(enum e_function function, char *rep);

void operand_to_string(enum e_operator operand, char *rep);
# endif /*_EPIQUATION_TEST_TREE_H_*/
