//List of function used to apply the operations of the variable on a result

# ifndef _EPIQUATION_VARIABLE_H_
# define _EPIQUATION_VARIABLE_H_

# include <stdlib.h>
# include <math.h>

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
**	init_variable: initialize a variable structure
**		name: the variable name
**	init_variable create a s_variable struct with default value
*/
struct s_variable *init_variable(char name);

/*
**	calcul_variable: calcul the value of the variable
**		var: the variable
**		val: the value of variable
**	calcul_variable apply the power and the multiplier of [var] to [val]
*/
float calcul_variable(struct s_variable *var, float val);


int are_same(struct s_variable *var1, struct s_variable *var2);

/*
**	free_variable: free a s_variable struct
**		var: the struct to free
*/
void free_variable(struct s_variable *var);

# endif /* _EPIQUATION_VARIABLE_H_ */
