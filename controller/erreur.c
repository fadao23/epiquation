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

char *get_string_erreur(int erreur)
{
  switch (erreur) {
    case 0:
      return NULL;
    case 1:
      return "No = symbole\n";
    case 2:
      return "More than one equal symbole\n";
    case 3:
      return "Nothing match in parsing\n";
    case 4:
      return "Division by zero\n";
    case 5:
      return "Negative value on logarithm\n";
    case 6:
      return "Negative value on sqrt\n";
    case 7:
      return "Unknow function\n";
    case 8:
      return "Value out of range on arcsin or arccos\n";
    case 9:
      return "Value out of range on arctan\n";
    case 10:
      return "Infinite number of value possible\n";
    case 11:
       return "Singular matrix\n";
    default:
      return "Unknow error\n";
  }
}

void free_erreur()
{
  int *erreur = get_erreur();
  free(erreur);
  erreur = NULL;
}
