# include "simplify.h"


void simplify_plus(struct s_tree *node, struct s_list *list, float *coef, int krisbool)
{
  if(!node)
    return;

  if(node->type == OPERAND && *((enum e_operator*) node->data) == PLUS)
  {
    if(krisbool == 0)
    {
      list = init_list();
      *coef = 0;
    }
    simplify_plus(node->left, list, coef, 1);
    simplify_plus(node->right, list, coef, 1);

    if(krisbool == 0 && list->next != NULL)
      rebuild_tree(list, *coef, 0);
  }

  else
  {
    if(krisbool == 1)
    {
      if (node->type == VALUE)
        *coef += *((float*)node->data);
      else
        push_list(list, node);
    }
    else
    {
      simplify_plus(node->left, list, coef, 0);
      simplify_plus(node->right, list, coef, 0);
    }
  }
}

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
		{
			simplify_minus(node->right, coef);
			simplify_minus(node->left, coef);
		}
	}
	else if (node->type == VALUE)
		*((float*) node->data) *= coef;
	else if (node->type == VARIABLE)
		((struct s_variable*) node->data)->mult *= coef;
	else
		((struct s_function*) node->data)->mult *= coef;
}



struct s_tree *rebuild_tree(struct s_list *list, float coef, int mult)
{
	struct s_tree *cur = pop_list(list);
	if(mult)
	{
		struct s_tree *tree = build_operator('*');
		multiplie_tree(&cur, coef, 0);
    tree->left = cur;
		if(size_list(list) > 1)
			tree->right = rebuild_tree(list, 1, 1);
		else
			tree->right = pop_list(list);
	}
	else
	{
	  struct s_tree *tree = build_operator('+');
    if(size_list(list) > 1)
      tree->right = rebuild_tree(list, coef, 0);
    else
    {
      float *tmp = malloc(sizeof (float));
      *tmp = coef;
      tree->right = build_float(tmp);
	  }
  }
	return cur;
}



void simplify_mult(struct s_tree *node, struct s_list *list, float *coef, int krisbool)
{
	if(!node)
		return;

	if(node->type == OPERAND && *((enum e_operator*) node->data) == TIME)
	{
		if(krisbool == 0)
		{
			list = init_list();
			*coef = 1;
		}
		simplify_mult(node->left, list, coef, 1);
		simplify_mult(node->right, list, coef, 1);

		if(krisbool == 0 && list->next != NULL)
			rebuild_tree(list, *coef, 1);
	}

	else
	{
		if(krisbool == 1)
		{
			if (node->type == VALUE)
				*coef *= *((float*)node->data);
			else
				push_list(list, node);
		}
		else
		{
			simplify_mult(node->left, list, coef, 0);
			simplify_mult(node->right, list, coef, 0);
		}
	}
}
