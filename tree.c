# include <stdlib.h>
# include <stdio.h>
# include "tree.h"

struct s_tree *create_node(enum e_type type, void *data)
{
  struct s_tree *create_node = malloc(sizeof(struct s_tree));
  create_node->left = NULL;
  create_node->right = NULL;
  create_node->type = type;
  create_node->data = data;

  return create_node;
}

int size_tree(struct s_tree *node)
{
  if (node == NULL)
    return 0;
  return size_tree(node->left) + size_tree(node->right) + 1;
}

void free_tree(struct s_tree *tree)
{
  if (tree == NULL)
    return;
  free_tree(tree->left);
  free_tree(tree->right);
  free(tree->data);
  free(tree);
}
