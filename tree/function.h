//function.h list of function used to manage function structure

# ifndef _EPIQUATION_FUNCTION_H_
# define _EPIQUATION_FUNCTION_H_

# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <err.h>

# include "../controller/erreur.h"

#define M_PI 3.14159265358979323846

/*
** enumeration used to list the differents mathematical functions
*/
enum e_function
{
  UNKNOW_F,
  EXP,
  LN,
  SQRT,
  POW,
  COS,
	ACOS,
  SIN,
	ASIN,
	TAN,
	ATAN
};

/*
** struct of function element
**   function: Identifiant of function
**   parameter: Optionnal array of parameter usefull for specifique function
**   power: power of the function
**   multiplier: multiplier of the function
*/
struct s_function
{
  enum e_function *function;
  float           param;
  int             power;
  float           mult;
};

/*
**	init_function: initialize a function structure
**		func: the name of function
**		para: optionnal parameter of function
** 	initialise a function struct with [func] and [para] parameter and default
**	value
*/
struct s_function *init_function(enum e_function *func, float para);

/*
**	get_function: get an e_function value
**		function: name of the function
**	get_function match an e_function value with [function] and return it.
**	Return unknow value if no match.
*/
enum e_function *get_function(char *function);

/*
**	calcul_function: calcul value of the function
**		function: the function
**		val: the value set to function
**	calcul_function calcul the value of [val] apply to the function then the
**	power and multiplier of [function]
*/
float calcul_function(struct s_function *function, float val);

float calcul_inverse(struct s_function *function, float val);

float calcul(struct s_function *function, float val);

/*
**	free_function: free a s_function struct
**		function: a structure to free
**	free_function free [function] pointeur before free the struct
*/
void free_function(struct s_function *function);

# endif /*_EPIQUATION_FUNCTION_H_*/
