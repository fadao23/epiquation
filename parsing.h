//parsing.h List of function used to parse and transform literal equation into BTree

# ifndef _EPIQUATION_PARSING_H_
# define _EPIQUATION_PARSING_H_

# include <stdlib.h>

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
**	get_pos_operator: get the position of higher priority operator
**		equation: string of part of an equation
**	get_pos_operator search the first occurence of operator in [equation] the
**	order of search is defined by priority order(we assume it isn't include
**	between any parenthesis), the priority order is *, /, +, -. The function
**	return the position of operator, -1 if they are not found.
*/
int get_pos_operator(char *equation);

/*
** 	get_operator: match an operator with the correspondant e_operator
**		operator: int value of operator charactere
**	get_operator return e_operator corresponding to [operator] (unknow if
**	operator didn't match)
*/
e_operator *get_operator(int num_operator);

/*
**	is_function: check if a string as a function pattern
**		function: string to check
**	is_function check if [function] corresponding with function pattern.
**	Function pattern is defined with the following regex:
**		^[a-z]{2,}\([0-9]+(\.[0-9]+)?(,[0-9]+(\.[0-9]+)?)*\)$
**	If pattern match, the function return 1 else it return 0.
*/
int is_function(char *function);

/*
**	get_function: get function from a string
**		function: string with data
**	get_function initialize a struct s_function variable with data stored in
**	[function]
**	Return the struct s_function or NULL if they are an error (unknow function
**	or a wrong number of parameter)
*/
struct s_function *get_function(char *function);

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
**	is_variable: check if a string is a variable
**		variable: string to check
**	is_variable check if [variable] is a number or a charactere, return 1 if
**	it's a number, 2 if it's a char, else 0.
*/
int is_variable(char *variable);

/*
**	get_number: get number from a string
**		number: string with a number
**	is_number transforme [number] into float
**	Return the float value
*/
float get_number(char *number);

/*
**	get_variable: initialise a s_variable
**		variable: the string with data
**	get_variable check if [variable] is a variable and initialize a struct
**	s_variable with data in string.
**	Return the s_variable or NULL if [variable] isn't a variable
*/
struct s_variable *get_variable(char *variable);

# endif /* _EPIQUATION_PARSING_H_ */
