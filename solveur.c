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
	int var_left = has_variable(tree->left);
	int var_right = has_variable(tree->right);
  if (var_right)
  {
		struct s_tree *res = get_not_var(tree->right);
		if (res != NULL)
			attache(&tree->left, res, (enum e_operator) tree->data); 
  }
}

struct s_tree *get_not_var(struct s_tree **tree)
{
	if (*tree->type == OPERAND)
	{
		if (!has_variable(*tree->left))
		{
			*tree = *tree->right;
			return *tree->left;
		}
		if (!has_variable(*tree->right))
		{
			*tree = *tree->left;
			return *tree->right;
		}
	}
	return NULL;
}

void attache(struct s_tree **node, struct s_tree *value, enum e_operator *oper)
{
	struct s_tree *new = malloc(sizeof (struct s_tree));
	new->type = OPERAND;
	new->data = malloc(sizeof (enum e_operator));
	new->data = &oper;
	new->left = *node;
	new->right = value;
	*node = new;
}
