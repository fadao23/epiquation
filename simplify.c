# ifndef _EPIQUATION_SIMPLIFY_H_
# define _EPIQUATION_SIMPLIFY_H_

# include "simplify.h"

float simplify_plus(struct s_tree *node, struct s_tree *tmp)
{
  if (node->type == VALUE)
    return *((float*)node->data);
  else if (node->type != OPERAND)
    return 0;
  else if ( )
  {
    simplify_plus()
  }
  return res;
}

# endif
