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
**  is_variable: check if a string is a variable
**    variable: string to check
**  is_variable check if [variable] is a number or a charactere, return 1 if
**  it's a number, 2 if it's a char, else 0.
*/
int is_variable(char *variable);

/*
**  get_variable: initialise a s_variable
**    variable: the string with data
**  get_variable check if [variable] is a variable and initialize a struct
**  s_variable with data in string.
**  Return the s_variable or NULL if [variable] isn't a variable
*/
struct s_variable *get_variable(char *variable);

/*
** Free s_variable struct
*/
void free_variable(struct s_variable *var);

# endif /* _EPIQUATION_VARIABLE_H_ */
