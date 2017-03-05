//parsing.h List of function used to parse and transform literal equation into BTree

# ifndef _EPIQUATION_PARSING_H_
# define _EPIQUATION_PARSING_H_

# include <sys/types.h>
# include <err.h>
# include <regex.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# include "tree.h"
# include "variable.h"
# include "function.h"
# include "operator.h"
# include "build.h"

/*
**	parse: get literal equation and transform it in Btree
**		equation: String of the literal equation
**	parse start the creation of the tree, it checks the presence of the equal
**	sign in [equation]
*/
struct s_tree *parse(char *equation);

/*
**	_parse: get a part of an equation and transform it into a BTree
**		equation: string of part of an equation
**	_parse create recursively the tree, it checks presence of patterns in the
**	following order: (We assume patterns aren't include in any parenthesis)
**		(1) search the operand with higher priority
**		(2) checks if all [equation] is a function
**		(3) checks if all [equation] is between parenthesis
**		(4) checks if all [equation] is a number or a variable
**	If nothing match the function return NULL in another case the pattern is
**	treated with differents strategie (WORK IN PROGRESS)
*/
struct s_tree *_parse(char *equation);

/*
**	clean_string: delete all non-printing charactere in a string
**		string: string to clean
**	clean_string create a new string and copy [string] without non-printing
**	caractere (except the end of string char)
**	return the new string
*/
char *clean_string(char *string);

/*
**  comp_regex: check if a string match a regex pattern
**    string: string to check
**		reg: regex expression
**  comp_regex return 1 if [string] match with [reg] pattern, 0 otherwise. An
**	error can be throw
*/
int comp_regex(char *string, char *reg);

# endif /* _EPIQUATION_PARSING_H_ */
