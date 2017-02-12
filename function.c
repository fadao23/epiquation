# include "function.h"

struct s_function *init_function(enum e_function *func,float *para)
{
	(void) func;
	(void) para;
	return NULL;
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
