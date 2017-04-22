# include "tree/tree.h"
# include "tree/build.h"
# include "calcul/solveur.h"
# include "parsing/parsing.h"
# include "controller/erreur.h"
# include <stdio.h>
# include <err.h>

int main(int argc, char *argv[])
{

  if(argc < 2)
    err(1,"Missing Argument");

  char *equation = clean_string(argv[1]);
  printf("Equation nettoyee :\n%s\n", equation);
  struct s_tree *node = parse(equation);

  if (*get_erreur())
  {
    printf("%s", get_string_erreur(*get_erreur()));
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
    printf("%s", get_string_erreur(*get_erreur()));
    free_tree(node);
    free_erreur();
    return -1;
  }
	printf("x = %f\n", res);

  free_tree(node);
  free_erreur();
  return 0;
}
