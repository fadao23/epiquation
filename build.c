# include "build.h"

struct s_tree *build(void)
{
  struct s_tree *node = malloc(sizeof (struct s_tree));
	node->left = NULL;
	node->right = NULL;
	return node;
}
struct s_tree *build_operator(char oper)
{
  struct s_tree *node = build();
  node->type = OPERAND;
  node->data = get_operator(oper);
	return node;
}

struct s_tree *build_function(char *func)
{
  struct s_tree *node = build();
  node->type = FUNCTION;
  node->data = init_function(get_function(func), 0);
	return node;
}

struct s_tree *build_variable(char *var)
{
  struct s_tree *node = build();
  node->type = VARIABLE;
  node->data = init_variable(*var);
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
  struct s_tree *node = build();
  node->type = VALUE;
  node->data = number;
 	return node;
}
