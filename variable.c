# include "variable.h"


struct s_variable create_s_var(char name)
{
  struct s_variable *var = malloc(sizeof(struct s_variable));

  s_var->name = name;
  s_var->power = 1;
  s_var->mult = 1;

  return s_var;
}


float (struct s_variable var, float res)
{

// differencier 4(x²) et (4x)²
//	res = 
}

void free_s_var(struct s_variable)
{
  //free(var);
}

