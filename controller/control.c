# include "control.h"

char *solve_equation(char *arg) {
  char *equation = clean_string(arg);
  printf("Equation nettoyee :\n%s\n", equation);
  struct s_tree *node = parse(equation);
  free(equation);
  int *err;
  if (*(err = get_erreur()))
  {
    char *s_err = get_string_erreur(*err);
    set_erreur(0);
    return s_err;
  }

  simplify_minus(&node, 1);
  float coef = 1;

  simplify_mult(&node, NULL, &coef, 0);

  simplify_plus(&node, NULL, &coef, 0);

  float res = solveur(node, 0, 1);

  if (*(err = get_erreur()))
  {
    char *s_err = get_string_erreur(*err);
    set_erreur(0);
    free_tree(node);
    return s_err;
  }

  char *r = calloc(200,sizeof(char));
  char *re = calloc(100,sizeof(char));
  char *test = "x = ";
  strcat(r,test);
  sprintf(re,"%f",res);
  strcat(r,re);
  free_tree(node);
  free(re);
  set_erreur(0);
  return r;
}

char *solve_system(char **system, int n) {
  void **pars = parsing_sys(system, n);
  float *matrix = (float*)  *pars;
  float *res    = (float*)  *(pars + 1);
  char  *var    = (char*)   *(pars + 2);

  int *indx = malloc(n * sizeof (int));

  ludcmp(matrix, n, indx);
  lubksb(matrix, n, indx, res);
  char *s = calloc(100, sizeof (char));
  for (int i = 0; i < n; ++i) {
    strncat(s, (var + i), 1);
    strcat(s, " = ");
    char *tmp = calloc(20, sizeof (char));
    sprintf(tmp, "%f\n", *(res + i));
    strcat(s, tmp);
  }

  free(indx);
  free(matrix);
  free(res);
  free(var);
  free(pars);
  int *err;
  if (*(err = get_erreur()))
    return get_string_erreur(*err);
  return s;
}
