//function.h list of function used to manage function structure

# ifndef _EPIQUATION_FUNCTION_H_
# define _EPIQUATION_FUNCTION_H_

# include <stdlib.h>
# include <math.h>
# include <string.h>
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
  SIN
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
  float           parameter;
  int             power;
  float           multiplier;
};

/*
  ** Function for make easily s_function
  ** Take all parameters of struct s_function
*/
struct s_function *init_function(enum e_function *func, float para);

enum e_function *get_function(char *function);

float calcul_function(struct s_function *function, float val);

/*
 ** Free s_function Struct
 ** Take struct s_function *function in argument
 */
void free_function(struct s_function *function);

# endif /*_EPIQUATION_FUNCTION_H_*/
