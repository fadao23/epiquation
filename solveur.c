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
  if (has_variable(tree->left))
  {

  }
}
