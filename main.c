# include "tree.h"
# include "build.h"
# include "solveur.h"
# include <stdio.h>

int main()
{
  //ln(4x) = 0
	struct s_tree *tree = build_operator('=');
	tree->left = build_function("ln");
  tree->left->left = build_variable("x");
  ((struct s_variable*)tree->left->left->data)->mult = 4;
	tree->right = build_number("0");
	printf("%f\n", solveur(tree, 0));
	free_tree(tree);
	return 0;
}
