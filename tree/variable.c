# include "variable.h"

struct s_variable *init_variable(char name)
{
  struct s_variable *var = malloc(sizeof(struct s_variable));
  var->name = name;
  var->power = 1;
  var->mult = 1;
  return var;
}

float calcul_variable(struct s_variable *var, float val)
{
  return pow(val, var->power) / var->mult;
}

int are_same(struct s_variable *var1, struct s_variable *var2)
{
  return (var1->name == var2->name && var1->power == var2->power
  && var1->mult == var2->mult);
}

void free_variable(struct s_variable *var)
{
  free(var);
}
