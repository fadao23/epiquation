# include "build.h"

struct s_tree *build_operator(char oper)
{
  struct s_tree *node = create_node(OPERAND, get_operator(oper));
	return node;
}

struct s_tree *build_function(char *func)
{
  struct s_tree *node = create_node(FUNCTION,
  init_function(get_function(func),0));
	return node;
}

struct s_tree *build_variable(char *var)
{
  struct s_tree *node = create_node(VARIABLE, init_variable(*var));
 	return node;
}

struct s_tree *build_number(char *number)
{
  float *res = malloc(sizeof (float));
  sscanf(number, "%f", res);
  return build_float(res);
}

struct s_tree *build_float(float *number)
{
  struct s_tree *node = create_node(VALUE, number);
  node->type = VALUE;
  node->data = number;
 	return node;
}
