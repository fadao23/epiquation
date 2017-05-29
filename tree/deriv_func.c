# include "derivate.h"

struct s_tree *deriv_exp(struct s_tree *node)
{
	struct s_tree *new = build_operator("*");
	new->left = deriv(node->left);
	new->right = build_function("exp");
  ((struct s_function*)new->right->data)->mult
    = ((struct s_function*)node->data)->mult;
  return new;
}

struct s_tree *deriv_ln(struct s_tree *node)
{
	struct s_tree *new = build_operator("*");
  new->left = deriv(node->left);
  multiplie_tree(new->left, ((struct s_function*) node->data)->mult);
  new->right = build_function("pow");
  ((struct s_function*)new->right->data)->param = -1;
	new->right->left = node->left;
  return new;
}

struct s_tree *deriv_sqrt(struct s_tree *node)
{
  struct s_tree *new = build_operator('*');
   new->left = deriv(node->left);
  multiplie_tree(new->left, ((struct s_function*) node->data)->mult);
  new->right = build_func("pow");
  ((struct s_function*)new->right->data)->param = -1;
  new->right->left = build_func("sqrt");
  new->right->left->left = node->left;
  return new;
}

struct s_tree *deriv_pow(struct s_tree *node)
{
  if(((struct s_function*)node->param)->param == 2)
    return deriv(node->left);
  struct s_tree *new = build_func("pow");
  ((struct s_function*) new->data)->mult
    = ((struct s_function*) node->data)->mult * ((struct s_function*) node->data)->pow;
  ((struct s_function*) new->data)->param
    = ((struct s_function*) node->data)->param - 1;
  new->left = deriv(node->left);
  return new;
}

struct s_tree *deriv_cos(struct s_tree *node)
{
  struct s_tree *new = build_operator('*');
  new->left = deriv(node->left);
  multiplie_tree(new->left, -1*((struct s_function*) node->data)->mult);
  new->right = build_function("sin");
  new->right->left = node->left;
  return new;
}

struct s_tree *deriv_sin(struct s_tree *node)
{
  struct s_tree *new = build_operator('*');
  new->left = deriv(node->left);
  multiplie_tree(new->left, ((struct s_function*) node->data)->mult);
  new->right = build_function("cos");
  new->right->left = node->left;
  return new;
}
