# include "tree.h"
# include "build.h"
# include "solveur.h"
# include "parsing.h"
# include <stdio.h>
# include <err.h>

int main(int argc, char *argv[])
{

  if(argc < 1)
    err(1,"Miising Argument");

  struct s_tree *node = parse(argv[1]);

  int size = size_tree(node);
  printf("%d\n",size);
  float coef = 1;
  simplify_mult(node, NULL, &coef, 0);
  size = size_tree(node);
  printf("%d\n",size);

  //ln(4x) = 0
  /*
  struct s_tree *tree = build_operator('=');
	tree->left = build_function("ln");
  tree->left->left = build_variable("x");
  ((struct s_variable*)tree->left->left->data)->mult = 4;
	tree->right = build_number("0");
	printf("%f\n", solveur(tree, 0));
  */

  free_tree(node);
  return 0;
}
