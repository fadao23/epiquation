# include "solveur.h"

int has_variable(struct s_tree *tree)
{
  if (tree == NULL)
    return 0;
  if (tree->type == VARIABLE)
    return 1;
  return has_variable(tree->left) || has_variable(tree->right);
}

float solveur(struct s_tree *tree)
{
	struct list *list_l	= malloc(sizeof (struct list));
	struct list *list_r = malloc(sizeof (struct list));
	struct list *li_l, *li_r;
	float res = 0;
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
			res += calc_no_var(pop_list(li_r));
		}
	}
	free_list(list_r);
	res = calcul_variable(list_l->next->tree->data, res);
	free_list(list_l);
	return res;
}

void _get_list(struct s_tree *node, struct list *list)
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
	return calc_no_var(node->left) + calc_no_var(node->right);
}
