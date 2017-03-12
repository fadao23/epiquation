# include "tree.h"
# include "build.h"
# include "solveur.h"
# include "parsing.h"
# include <stdio.h>
# include <err.h>

# include "test_tree.h"
int main(int argc, char *argv[])
{

  if(argc < 2)
    err(1,"Missing Argument");

  struct s_tree *node = parse(argv[1]);
  printf("minus\n");
  simplify_minus(&node, 1);
  tree_to_string(node);
  float coef = 1;

  printf("mult\n");
  simplify_mult(&node, NULL, &coef, 0);
  tree_to_string(node);

	printf("x = %f\n", solveur(node, 0, 1));

  free_tree(node);
  return 0;
}
