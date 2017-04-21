//operator.h declare enum for operator

# ifndef _EPIQUATION_OPERATOR_H_
# define _EPIQUATION_OPERATOR_H_

# include <stdlib.h>
# include <string.h>

/*
** enum used to list operands
*/
enum e_operator
{
  UNKNOW,
  EQUAL,
	TIME,
	PLUS,
	MINUS
};

/*
**  get_pos_operator: get the position of higher priority operator
**    equation: string of part of an equation
**  get_pos_operator search the first occurence of operator in [equation] the
**  order of search is defined by priority order(we assume it isn't include
**  between any parenthesis), the priority order is *, /, +, -. The function
**  return the position of operator, -1 if they are not found.
*/
int get_pos_operator(char *equation);

/*
**  get_operator: match an operator with the correspondant e_operator
**    operator: int value of operator charactere
**  get_operator return e_operator corresponding to [operator] (unknow if
**  operator didn't match)
*/
enum e_operator *get_operator(int num_operator);

# endif /*_EPIQUATION_OPERATOR_H_*/
