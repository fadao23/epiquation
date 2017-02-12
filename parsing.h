//parsing.h List of function used to parse and transform literal equation into BTree

# ifndef _EPIQUATION_PARSING_H_
# define _EPIQUATION_PARSING_H_

# include <stdlib.h>
# include <string.h>

# include "tree.h"
# include "variable.h"
# include "function.h"
# include "operator.h"

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
**	is_number: check if a string is a number
**		number: string to check
**	is_number check if [number] corresponding with number pattern.
**	Number pattern is defined by the following regex:
**		^[0-9]+(\.[0-9]+)?$
**	Return 1 if pattern match else return 0
*/
int is_number(char *number);

/*
**	get_number: get number from a string
**		number: string with a number
**	is_number transforme [number] into float
**	Return the float value
*/
float get_number(char *number);

# endif /* _EPIQUATION_PARSING_H_ */
