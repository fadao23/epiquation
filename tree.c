# include <stdlib.h>
# include <stdio.h>
# include "tree.h"

void free_tree(struct s_tree *tree)
{
  free(tree->left);
  free(tree->right);
  free(tree->data);
  free(tree);
}

struct s_tree *create_node(enum e_type type, void *data)
{
  struct s_tree *create_node = malloc(sizeof(struct s_tree));
  create_node->left = NULL;
  create_node->right = NULL;
  create_node->type = type;
  create_node->data = data;

  return create_node;
}
