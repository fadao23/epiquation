# include "calcul.h"

void multiplie_tree(struct s_tree *node, float coef)
{
  if (node == NULL || coef == 1)
    return;

  if (node->type == OPERAND)
  {
    if(*((enum e_operator*)node->data) == PLUS)
      multiplie_tree(node->right,coef);
    multiplie_tree(node->left,coef);
  }
  else if (node->type == VALUE)
    (*(float*)node->data) *= coef;
  else if (node->type == VARIABLE)
    ((struct s_variable*)node->data)->mult *= coef;
  else if (node->type == FUNCTION)
    ((struct s_function*)node->data)->mult *= coef;
}
