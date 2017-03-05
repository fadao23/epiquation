# include "build.h"

struct s_tree *build_operator(char oper)
{
  struct s_tree *node = malloc(sizeof (struct s_tree));
  node->type = OPERAND;
  node->data = get_operator(oper);
  return node;
}

struct s_tree *build_function(char *func)
{
  struct s_tree *node = malloc(sizeof (struct s_tree));
  node->type = FUNCTION;
  node->data = init_function(get_function(func), 0);
  return node;
}

struct s_tree *build_variable(char *var)
{
  struct s_tree *node = malloc(sizeof (struct s_tree));
  node->type = VARIABLE;
  node->data = init_variable(*var);
  return node;
}

struct s_tree *build_number(char *number)
{
  struct s_tree *node = malloc(sizeof (struct s_tree));
  float *res = malloc(sizeof (float));
  sscanf(number, "%f", res);
  node->type = VALUE;
  node->data = res;
  return node;
}
