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

int is_function(char *function)
{
	(void) function;
	return 0;
}

struct s_function *get_function(char *function)
{
	(void) function;
	return NULL;
}

void free_function(struct s_function *function)
{
  free(function->function);
  free(function->parameter);
  free(function);
}
