# include "variable.h"

struct s_variable *init_variable(char name)
{
  struct s_variable *var = malloc(sizeof(struct s_variable));

  var->name = name;
  var->power = 1;
  var->mult = 1;
  return var;
}

float calcul_variable(struct s_variable *var)
{
	(void) var;
	return 0;
// differencier 4(x²) et (4x)²
//	res = 
}

struct s_variable *get_variable(char *variable)
{
	(void) variable;
	return NULL;
}

void free_variable(struct s_variable *var)
{
	(void) var;
  //free(var);
}
