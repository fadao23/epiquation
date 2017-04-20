# include "interface.h"

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
  return s;
}

/*int main() {
  float c[3][3] = {{1,3,6},{2,8,16},{5,21,45}};
  float *a = malloc(9*sizeof (int));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <3; ++j)
      *(a+i*3+j) = c[i][j];
  }
  char **system = malloc(3 * sizeof (char*));
  *system = "1x+2b+5c=1";
  *(system + 1) = "3x + 8b + 21c = 2";
  *(system + 2) = "6x + 16b + 45c = 3";
  char *s = solve_system(system, 3);
  printf("%s", s);

  return 0;
}*/
