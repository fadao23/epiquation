# include "tree.h"
# include "build.h"
# include "solveur.h"
# include "parsing.h"
# include "erreur.h"
# include <stdio.h>
# include <err.h>

int main(int argc, char *argv[])
{

  if(argc < 2)
    err(1,"Missing Argument");

  struct s_tree *node = parse(argv[1]);

  if (*get_erreur())
  {
    print_erreur();
    free_erreur();
    return -1;
  }

  simplify_minus(&node, 1);
  float coef = 1;

  simplify_mult(&node, NULL, &coef, 0);

  simplify_plus(&node, NULL, &coef, 0);

  float res = solveur(node, 0, 1);

  if (*get_erreur())
  {
    print_erreur();
    free_tree(node);
    free_erreur();
    return -1;
  }
	printf("x = %f\n", res);

  free_tree(node);
  free_erreur();
  return 0;
}
