//List of function used to manage a binary tree

# ifndef _EPIQUATION_TREE_H_
# define _EPIQUATION_TREE_H_

# include <stdlib.h>

# include "operator.h"

/*
**  enumeration used to list type of node
*/
enum e_type
{
	operand,
	function,
	variable,
	value
};

/*
**  struct of BTree element
**    left: the left child
**    right: the right child
**    type : the type of the data
**    data: the data of the node
*/
struct          s_tree
{
	struct s_tree *left;
	struct s_tree *right;
	enum e_type   type;
	void          *data;
};

/*
**	create_node: create a node
**		type: type of the data
**		data: data of the node
**	create_node create a node whose children are set to NULL
*/
struct s_tree *create_node(enum e_type type, void *data);

/*
**	free_tree: free a tree
**	free_tree free all the tree and data in
*/
void free_tree(struct s_tree *tree);

# endif /* _EPIQUATION_TREE_H_ */
