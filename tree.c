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

int get_prof(struct s_tree *node)
{
	if (node == NULL)
		return 0;
	if(node->type == OPERAND)
	{
		int prof = get_prof(node->left);
		int prof_r = get_prof(node->right);
		prof = prof > prof_r ? prof : prof_r;
		return prof + 1;
	}
	return 1 + get_prof(node->left);
}

void free_tree(struct s_tree *tree)
{
	if (tree == NULL)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	if (tree->type == VARIABLE)
		free_variable(tree->data);
	else if (tree->type == FUNCTION)
		free_function(tree->data);
	else
		free(tree->data);
	free(tree);
}
