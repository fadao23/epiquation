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
  int type;
  float valeur, div = 1;
  if (egal)
  {
	  type = _get_list(tree->left, list_l, -1);
	  _get_list(tree->right, list_r, type);
	}
  else
	  type = _get_list(tree, list_l, -1);
  li_l = list_l;
	while (li_l->next)
	{
		if (!has_variable(li_l->next->tree))
    {
      struct s_tree *tmp = pop_list(li_l);
      if (type != 1)
      {
        simplify_minus(&tmp, -1);
			  res += calc_no_var(tmp);
		  }
      else
      {
        valeur = calc_no_var(tmp);
        if(valeur == 0)
          set_erreur(4);
        else
          div *= valeur;
      }
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
  res /= div;
	free_list(list_r);
  res = calc_res(list_l, res, type);
	free_list(list_l);
	return res;
}

void change(struct s_list *from, struct s_list *to)
{
  simplify_minus(&from->next->tree, -1);
  change_list(from, to);
}

int _get_list(struct s_tree *node, struct s_list *list,  int val)
{
  if(!node)
    return -1;

  int res = val;
  if (node->type == OPERAND && *((enum e_operator*)node->data) == PLUS && (val
  == -1 || val == 0))
    res = 0;
  else if (node->type == OPERAND && *((enum e_operator*)node->data) == TIME &&
  (val == -1 || val == 1))
    res = 1;
  else
  {
    push_list(list, node);
    return val;
  }
  res = _get_list(node->left, list, res);
  res = _get_list(node->right, list, res);
  return res;
}

float calc_no_var(struct s_tree *node)
{
	if (node->type == FUNCTION)
		return calcul_function((struct s_function*) node->data,
		calc_no_var(node->left));
	if (node->type == VALUE)
		return *((float*) node->data);
  enum e_operator op =*((enum e_operator*) node->data);
  if (op == PLUS)
	  return calc_no_var(node->left) + calc_no_var(node->right);
  if (op == TIME)
	  return calc_no_var(node->left) * calc_no_var(node->right);
  err(1,"Case undefined calc_no_var");
  return 0;
}

float calc_res(struct s_list *l, float egal, int type)
{
  int cpt = type == 1 ? 1 : 0, var = 0;
  struct s_tree *node = NULL;
  while (l->next)
  {
    node = pop_list(l);
    if (node->type == VARIABLE)
    {
      var = 1;
      if (type == 1)
        cpt *= ((struct s_variable*)node->data)->mult;
      else
      {
        cpt += ((struct s_variable*)node->data)->mult;
      }
    }
  }
  //if (plus && type != 1 && bcl > 1)
  //  cpt--;
  if (cpt == 0 && var)
    set_erreur(10);
  if (node->type == VARIABLE)
  {
    ((struct s_variable*)node->data)->mult = cpt;
    return calcul_variable((struct s_variable*) node->data, egal);
  }
  if (node->type == FUNCTION)
  {
    egal = calcul_inverse(node->data, egal);
    return solveur(node->left, egal, 0);
  }
  return 0;
}
