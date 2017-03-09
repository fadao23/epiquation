//build.h have function use to build a tree

# ifndef _EPIQUATION_BUILD_H_
# define _EPIQUATION_BUILD_H_

# include <stdio.h>
# include <stdlib.h>

# include "tree.h"
# include "variable.h"
# include "function.h"
# include "operator.h"

/*
**  build_operator: get node from an operator char
**    oper: char with operator
**  Return the node containing [oper] information
*/
struct s_tree *build_operator(char oper);

/*
**  build_function: get node from a function string
**    function: string with data
**  Return the struct s_tree containing function information
*/
struct s_tree *build_function(char *function);

/*
**  build_variable: get node from a variable string
**    variable: the string with data
**  Return the struct s_tree containing variable information
*/
struct s_tree *build_variable(char *var);

/*
**  build_number: get node from a number string
**    number: string with a number
**  Return the struct s_tree containing number information
*/
struct s_tree *build_number(char *number);

# endif /*_EPIQUATION_BUILD_H_*/
