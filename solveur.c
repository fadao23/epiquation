# include "solveur.h"

int has_variable(struct s_tree *tree)
{
  if (tree == NULL)
    return 0;
  if (tree->type == VARIABLE)
    return 1;
  return has_variable(tree->left) || has_variable(tree->right);
}

float solveur(struct s_tree *tree, float res, int egal)
{
	struct s_list *list_l	= init_list();
	struct s_list *list_r = init_list();
	struct s_list *li_l;
  if (egal)
  {
	  _get_list(tree->left, list_l);
	  _get_list(tree->right, list_r);
	}
  else
	  _get_list(tree, list_l);
  li_l = list_l;
	while (li_l->next)
	{
		if (!has_variable(li_l->next->tree))
    {
      struct s_tree *tmp = pop_list(li_l);
      simplify_minus(&tmp, -1);
			res += calc_no_var(tmp);
		}
    else
			li_l = li_l->next;
	}
	while (list_r->next)
	{
		if(has_variable(list_r->next->tree))
		  change(list_r, li_l);
    else
		{
      struct s_tree *tmp = pop_list(list_r);
			res += calc_no_var(tmp);
		}
	}
	free_list(list_r);
  res = calc_res(list_l, res);
	free_list(list_l);
	return res;
}

void change(struct s_list *from, struct s_list *to)
{
  simplify_minus(&from->next->tree, -1);
  change_list(from, to);
}

void _get_list(struct s_tree *node, struct s_list *list)
{
  if(!node)
    return;
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
  err(1,"Case undefined calc_no_var");
  return 0;
}

float calc_res(struct s_list *l, float egal)
{
  int cpt = 0;
  struct s_tree *node;
  while (l->next)
  {
    node = pop_list(l);
    cpt += ((struct s_variable*)node->data)->mult;
  }
  ((struct s_variable*)node->data)->mult = cpt;
  if (node->type == VARIABLE)
    return calcul_variable((struct s_variable*) node->data, egal);
  if (node->type == FUNCTION)
    return solveur(node->left, calcul_inverse(node->data, egal), 0);
  return 0;
}
