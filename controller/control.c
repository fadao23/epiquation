# include "control.h"

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
