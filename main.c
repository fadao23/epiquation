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
  simplify_minus(node, 1);
  float coef = 1;
  simplify_mult(&node, NULL, &coef, 0);

	printf("x = %f\n", solveur(node, 0));

  free_tree(node);
  return 0;
}
