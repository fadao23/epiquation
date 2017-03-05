# include "simplify.h"

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


void simplify_minus(struct s_tree *node, int coef)
}
	if (node->type == OPERAND)
	{
		if (*node->data == MINUS)
		{
			simplify_minus(tree->right, coef * (-1));
			*node->data = PLUS;
		}
		else
			simplify_minus(tree->right, coef);
		simplify_minus(tree->left, coef);
	}

	else if (node->type == VALUE)
		*node->data *= coef;

	else
		node->data->multiplier *= coef;
}
