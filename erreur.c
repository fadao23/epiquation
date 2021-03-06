# include "erreur.h"

int *get_erreur(void)
{
  static int *erreur = NULL;
  if(erreur == NULL)
  {
    erreur = malloc(sizeof (int));
    *erreur = 0;
  }
  return erreur;
}

void set_erreur(int x)
{
  int *erreur = get_erreur();
  *erreur = x;
}

void print_erreur(void)
{
  int *erreur = get_erreur();
  if (*erreur == 0)
    return;
  if(*erreur == 1)
    printf("No = symbole\n");
  else if (*erreur == 2)
    printf("More than one equal symbole\n");
  else if (*erreur ==  3)
    printf("Nothing match in parsing\n");
  else if (*erreur == 4)
    printf("Division by zero\n");
  else if (*erreur == 5)
    printf("Negative value on logarithm\n");
  else if (*erreur == 6)
    printf("Negative value on sqrt\n");
  else if (*erreur == 7)
    printf("Unknow function\n");
  else if (*erreur == 8)
    printf("Value out of range on arcsin or arccos\n");
  else if (*erreur == 9)
    printf("Value out of range on arctan\n");
  else if (*erreur == 10)
    printf("Infinite number of value possible\n");
  else
    printf("Unknow error\n");
}

void free_erreur()
{
  int *erreur = get_erreur();
  free(erreur);
  erreur = NULL;
}
