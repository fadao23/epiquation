# include "function.h"

struct s_function *init_function(enum e_function *func,float *para)
{
  struct s_function *fun = malloc(sizeof(struct s_function));
  fun->function = func;
  fun->parameter = para;
  fun->power = 1;
  fun->multiplier = 1;
	return fun;
}

float calcul_function(struct s_function *function)
{
	(void) function;
	return 0;
}

void free_function(struct s_function *function)
{
  free(function->function);
  free(function->parameter);
  free(function);
}
