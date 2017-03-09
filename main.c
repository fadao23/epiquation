# include "tree.h"
# include "build.h"
# include "solveur.h"
# include <stdio.h>

int main()
{
	struct s_tree *tree = build_operator('=');
	tree->left = build_operator('+');
	tree->left->left = build_variable("x");
	((struct s_variable*)tree->left->left->data)->mult = 3;
	tree->left->right = build_number("4");
	tree->right = build_number("19");
	printf("%f\n", solveur(tree));
	free_tree(tree);
	return 0;
}
