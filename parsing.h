//parsing.h List of function used to parse and transform literal equation into BTree

# ifndef _EPIQUATION_PARSING_H_
# define _EPIQUATION_PARSING_H_

# include <err.h>
# include <regex.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

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
**  comp_regex: check if a string match a regex pattern
**    string: string to check
**		reg: regex expression
**  comp_regex return 1 if [string] match with [reg] pattern, 0 otherwise. An
**	error can be throw
*/
int comp_regex(char *string, char *reg);

/*
**  get_function: get function from a string
**    function: string with data
**  get_function initialize a struct s_function variable with data stored in
**  [function]
**  Return the struct s_function or NULL if they are an error (unknow function
**  or a wrong number of parameter)
*/
struct s_tree *build_function(char *function);

/*
**  get_variable: initialise a s_variable
**    variable: the string with data
**  get_variable check if [variable] is a variable and initialize a struct
**  s_variable with data in string.
**  Return the s_variable or NULL if [variable] isn't a variable
*/
struct s_tree *build_variable(char *var);

/*
**	get_number: get number from a string
**		number: string with a number
**	is_number transforme [number] into float
**	Return the float value
*/
struct s_tree *build_number(char *number);

# endif /* _EPIQUATION_PARSING_H_ */
