# include "simplify.h"


void simplify_plus(struct s_tree **node, struct s_list *list, float *coef, int krisbool)
{
  if(!*node)
    return;

  if((*node)->type == OPERAND && *((enum e_operator*) (*node)->data) == PLUS)
  {
    if(krisbool == 0)
    {
      list = init_list();
      *coef = 0;
    }
    simplify_plus(&(*node)->left, list, coef, 1);
    simplify_plus(&(*node)->right, list, coef, 1);

    (*node)->left = NULL;
    (*node)->right = NULL;
    free_tree(*node);

    if(krisbool == 0 && list->next != NULL)
    {
			*node = rebuild_tree(list, *coef, 0);
      free_list(list);
      list = NULL;
    }
    else
      *node = NULL;
  }

  else
  {
    if(krisbool == 1)
    {
      if ((*node)->type == VALUE)
      {
		    *coef += *((float*)(*node)->data);
			  free_tree(*node);
        *node = NULL;
      }

      else
        push_list(list, *node);
    }
    else
    {
      simplify_plus(&(*node)->left, list, coef, 0);
      simplify_plus(&(*node)->right, list, coef, 0);
    }
  }
}

void simplify_minus(struct s_tree **node, int coef)
{
  if(!*node)
    return;
	if ((*node)->type == OPERAND)
	{
		if (*((enum e_operator*) (*node)->data) == MINUS)
		{
			simplify_minus(&(*node)->right, coef * (-1));
      if ((*node)->left == NULL)
      {
        struct s_tree *tmp = (*node)->right;
        (*node)->right = NULL;
        free_tree(*node);
        *node = tmp;
      }
      else
      {
			  *((enum e_operator*) (*node)->data) = PLUS;
		    simplify_minus(&(*node)->left, coef);
		  }
    }
		else if (*((enum e_operator*) (*node)->data) == TIME)
		{
			simplify_minus(&(*node)->right, coef);
		}
    else
    {
		  simplify_minus(&(*node)->right, coef);
		  simplify_minus(&(*node)->left, coef);
	  }
  }
	else if ((*node)->type == VALUE)
		*((float*) (*node)->data) *= coef;
	else if ((*node)->type == VARIABLE)
		((struct s_variable*) (*node)->data)->mult *= coef;
  else
	{
    ((struct s_function*) (*node)->data)->mult *= coef;
		simplify_minus(&(*node)->left, 1);
  }
}



struct s_tree *rebuild_tree(struct s_list *list, float coef, int mult)
{
  struct s_tree *cur, *tree;
  float *tmp, neutre;
  int size = size_list(list);

  if (size)
  {
    cur = pop_list(list);
    size--;
    if (mult)
    {
      neutre = 1;
      simplify_mult(&cur, NULL, &neutre, 0);
      multiplie_tree(&cur, coef, 1);
      if(size)
      {
        tree = build_operator('*');
        tree->left = cur;
        if(size > 1)
          tree->right = rebuild_tree(list, 1, mult);
        else
          tree->right = pop_list(list);
      }
      else
        tree = cur;
    }
    else
    {
      neutre = 0;
      simplify_plus(&cur, NULL, &neutre, 0);
      tree = build_operator('+');
      tree->left = cur;
      tree->right = rebuild_tree(list, coef, mult);
    }
    return tree;
  }
  tmp = malloc(sizeof (float));
  *tmp = coef;
  return build_float(tmp);
}

void simplify_mult(struct s_tree **node, struct s_list *list, float *coef, int krisbool)
{
	if(!*node)
		return;

	if((*node)->type == OPERAND && *((enum e_operator*)(*node)->data) == TIME)
	{
		if(krisbool == 0)
		{
			list = init_list();
			*coef = 1;
		}
		simplify_mult(&(*node)->left, list, coef, 1);
		simplify_mult(&(*node)->right, list, coef, 1);

    (*node)->left = NULL;
    (*node)->right = NULL;
    free_tree(*node);


		if(krisbool == 0 && list != NULL)
    {
			*node = rebuild_tree(list, *coef, 1);
      free_list(list);
      list = NULL;
    }
    else
      *node = NULL;
	}

	else
	{
		if(krisbool == 1)
		{
			if ((*node)->type == VALUE)
      {
				*coef *= *((float*)(*node)->data);
			  free_tree(*node);
        *node = NULL;
      }
      else
				push_list(list, *node);
		}
		else
		{
			simplify_mult(&(*node)->left, list, coef, 0);
			simplify_mult(&(*node)->right, list, coef, 0);
		}
	}
}
