# include "variable.h"

struct s_variable *init_variable(char *name)
{
  struct s_variable *var = malloc(sizeof(struct s_variable));
  var->name = name;
  var->power = 1;
  var->mult = 1;
  return var;
}

float calcul_variable(struct s_variable *var, float val)
{
  float	res = 0;
  return res = var->mult * pow(val, var->power);
}

void free_variable(struct s_variable *var)
{
  free(var);
}
