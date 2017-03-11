# include "calcul.h"

void multiplie_tree(struct s_tree **node, float coef, int bol)
{

  float r;
  struct s_tree *tmp;
  if (node == NULL)
    return;
  if (!bol)
  {
    if ((*node)->type == OPERAND && *((enum e_operator*)(*node)->data) == TIME)
    {
      if (((*node)->left->type) == VALUE)
      {
        r = *((float*)(*node)->left->data);
        multiplie_tree(&(*node)->right,r,1);
        tmp = *node;
        *node = (*node)->right;
        tmp->right = NULL;
        free_tree(tmp);
        return;
      }
      if((*node)->right->type == VALUE)
      {
        r = *((float*)(*node)->right->data);
        multiplie_tree(&(*node)->left,r,1);
        tmp = *node;
        *node = (*node)->left;
        tmp->left = NULL;
        free_tree(tmp);
        return;
      }
    }
    multiplie_tree(&(*node)->right,coef,0);
    multiplie_tree(&(*node)->left,coef,0);
  }
  else
  {
    if ((*node)->type == OPERAND)
    {
      if(*((enum e_operator*)(*node)->data) == MINUS  || *((enum
              e_operator*)(*node)->data) == PLUS){
        multiplie_tree(&(*node)->right,coef,1);
      }
      multiplie_tree(&(*node)->left,coef,1);
    }
    if ((*node)->type == VALUE)
    {
      (*(float*)(*node)->data) *= coef;
    }
    if ((*node)->type == VARIABLE)
    {
      ((struct s_variable*)(*node)->data)->mult *= coef;
    }
    if ((*node)->type == FUNCTION)
    {
      ((struct s_function*)(*node)->data)->mult *= coef;
    }
  }
}
