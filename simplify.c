# include "simplify.h"

/*
float simplify_plus(struct s_tree *node, struct s_tree *tmp)
{
  if (node->type == VALUE)
    return *((float*)node->data);
  else if (node->type != OPERAND)
    return 0;
  else if ( )
  {
    simplify_plus()
  }
  return res;
}
*/

void simplify_minus(struct s_tree *node, int coef)
{
	if (node->type == OPERAND)
	{
		if (*((enum e_operator*) node->data) == MINUS)
		{
			simplify_minus(node->right, coef * (-1));
			*((enum e_operator*) node->data) = PLUS;
		}
		else
			simplify_minus(node->right, coef);
		simplify_minus(node->left, coef);
	}

	else if (node->type == VALUE)
		*((float*) node->data) *= coef;

	else if (node->type == VARIABLE)
		((struct s_variable*) node->data)->mult *= coef;
	else
		((struct s_function*) node->data)->multiplier *= coef;
}
