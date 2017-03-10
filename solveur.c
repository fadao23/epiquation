# include "solveur.h"

int has_variable(struct s_tree *tree)
{
  if (tree == NULL)
    return 0;
  if (tree->type == VARIABLE)
    return 1;
  return has_variable(tree->left) || has_variable(tree->right);
}

float solveur(struct s_tree *tree, float res)
{
	struct s_list *list_l	= malloc(sizeof (struct s_list));
	struct s_list *list_r = malloc(sizeof (struct s_list));
	struct s_list *li_l, *li_r;
	list_l->next = NULL;
	list_r->next = NULL;
	_get_list(tree->left, list_l);
	_get_list(tree->right, list_r);
	li_l = list_l;
	li_r = list_r;
	while (li_l->next)
	{
		if (!has_variable(li_l->next->tree))
		{
			simplify_minus(li_l->next->tree, -1);
			change_list(li_l, li_r);
		}
		else
			li_l = li_l->next;
	}
	while (li_r->next)
	{
		if(has_variable(li_r->next->tree))
			change_list(li_r, li_l);
		else
		{
      struct s_tree *tmp = pop_list(li_r);
			res += calc_no_var(tmp);
      free_tree(tmp);
		}
	}
	free_list(list_r);
  res = calc_res(list_l, res);
	free_list(list_l);
	return res;
}

void _get_list(struct s_tree *node, struct s_list *list)
{
  if (node->type == OPERAND && *((enum e_operator*)node->data) == PLUS)
  {
    _get_list(node->left, list);
    _get_list(node->right, list);
  }
  else
    push_list(list, node);
}

float calc_no_var(struct s_tree *node)
{
	if (node->type == FUNCTION)
		return calcul_function((struct s_function*) node->data,
		calc_no_var(node->left));
	if (node->type == VALUE)
		return *((float*) node->data);
  if (node->type != OPERAND)
    err(1,"variable in calc no var");
  enum e_operator op =*((enum e_operator*) node->data);
  if (op == PLUS)
	  return calc_no_var(node->left) + calc_no_var(node->right);
  if (op == MINUS)
	  return calc_no_var(node->left) - calc_no_var(node->right);
  if (op == TIME)
	  return calc_no_var(node->left) * calc_no_var(node->right);
  if (op == SLASH)
    return calc_no_var(node->left) / calc_no_var(node->right);
  err(1,"Case undefined calc_no_var");
  return 0;
}

float calc_res(struct s_list *l, float egal)
{
  //if (size_list(l) == 1)
  {
    struct s_tree *node = l->next->tree;
    if (node->type == VARIABLE)
      return calcul_variable((struct s_variable*) node->data, egal);
    //if (node->type == FUNCTION)
      //enlever la node function et appliquer l'inverse sur res
  }
  return 0;
}
