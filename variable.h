//List of function used to apply the operations of the variable on a result

# ifndef _EPIQUATION_VARIABLE_H_
# define _EPIQUATION_VARIABLE_H_

# include <stdlib.h>

/*
 ** struct of variable element
 **		name : Name of the variable
 **		Power : Power of the variable
 **		Mult : Multiplier of the variable
 */
struct          s_variable
{
  char          name;
  int           power;
  float         mult;
};


/*
 ** initialise the structure of the variable
 **
*/
struct s_variable *init_variable(char name);

/*
 ** Apply the power and the multiplier of the variable
 **		to a float result
 */
float calcul_variable(struct s_variable *var);

/*
** Free s_variable struct
*/
void free_variable(struct s_variable *var);

# endif /* _EPIQUATION_VARIABLE_H_ */
