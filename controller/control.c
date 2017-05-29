# include "control.h"

char *solve_equation(char *arg) {
  char *equation = clean_string(arg);
  printf("Equation nettoyee :\n%s\n", equation);
  struct s_tree *node = parse(equation, 1);
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
  sprintf(r,"x = %f",res);
  free_tree(node);
  set_erreur(0);
  return r;
}

char *solve_polynome(const char **coefs) {
  float a = get_float(*coefs);
  float b = get_float(*(coefs + 1));
  float c = get_float(*(coefs + 2)) - get_float(*(coefs + 3));
  char **res = malloc(3 * sizeof (char*));
  int nb_rac = sec_deg(a, b, c, res);
  char *s_res = calloc(400, sizeof (char));
  if (nb_rac > 0)
    sprintf(s_res, "Le polynome à un delta:\n d = b²-4ac = %s\n\nIl a donc %d racines réel:\n", *res, nb_rac);
  else
    sprintf(s_res, "Le polynome à un delta:\n d = b²-4ac = %s\n\nIl a donc 2 racines imaginaire:\n", *res);
  if (nb_rac == 1)
    sprintf(s_res,"%s x = (-b)/(2a) = %s\n", s_res, *(res + 1));
  else if (nb_rac == 2)
    sprintf(s_res,"%s x1 = (-b-sqrt(d))/(2a) = %s\n x2 =  (-b+sqrt(d))/(2a) = %s\n", s_res, *(res + 1), *(res + 2));
  else
    sprintf(s_res,"%s x1 = (-b-i*sqrt(d))/(2a) = %s\n x2 =  (-b+i*sqrt(d))/(2a) = %s\n", s_res, *(res + 1), *(res + 2));
  free(res);
  return s_res;
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

char *derivate_equation(char *arg) {
  char *equation = clean_string(arg);
  printf("Equation nettoyee :\n%s\n", equation);
  struct s_tree *node = parse(equation, 0);
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
  simplify_pow(&node);
  tree_to_string(node);
  struct s_tree *res = deriv(node);
  
  if (*(err = get_erreur()))
  {
    char *s_err = get_string_erreur(*err);
    set_erreur(0);
    free_tree(node);
    return s_err;
  }

  //char *r = calloc(200,sizeof(char));
  tree_to_string(res);
  free_tree(node);
  set_erreur(0);
  return "";
}

