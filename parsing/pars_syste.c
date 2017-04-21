# include "parsing.h"

void **parsing_sys(char **system, int n)
{
  char *v = calloc(n, sizeof (char));
  float *matrix = malloc(n * n * sizeof (float));
  float *res = calloc(n, sizeof (float));
	for (int i = 0; i < n; i++)
	{
		char *s = *(system + i);
    while(*(s) != 0)
		{
			int pos;
      char var;
			int t = get_next(s, &pos, &var);
			char *coef = clean(s, pos);
      float tmp;
			if(t == 1) {
        int rng = get_rang(v, n, var);
        if(rng > -1)
          sscanf(coef,"%f",(matrix + i * n + rng));
        else {
          sscanf(coef,"%f", &tmp);
          *(res + i) -= tmp;
        }
      }
      else {
        sscanf(coef,"%f", &tmp);
        *(res + i) += tmp;
        break;
      }
      s = s + pos + 1;
    }
	}
  void **tab = malloc(3 * sizeof (void*));
  *tab = matrix;
  *(tab + 1) = res;
  *(tab + 2) = v;
  return tab;
}

int get_rang(char *vs, int n, char v) {
  for (int i = 0; i < n; ++i) {
    if (*(vs + i) == 0) {
      *(vs + i) = v;
      return i;
    }
    if (*(vs + i) == v)
      return i;
  }
  return -1;
}

int get_next(char *s, int *i, char *v)
{
	*i = 0;
  *v = 0;
  int blank = 1;
	while (*(s + *i) != '\0')
	{
    if(blank &&*(s + *i) !=' ')
      blank = 0;
		else if(*(s + *i) >= 'a' && *(s + *i) <= 'z')
      *v = *(s +  *i);
		else if((*(s + *i) == '-' && blank) || *(s + *i) == '+' || *(s + *i) == '=')
			return 1;
		(*i)++;
	}
	return 2;
}

char *clean(char *s, int max)
{
	char *r = calloc(10, sizeof(char));
	int i = 0, id = 0;
	while(i < max)
	{
		if((*(s + i) >= '0' && *(s + i) <= '9') || *(s + i) == '.'
    || *(s + i) == '-')
			*(r + id++) = *(s + i);
		i++;
	}
  return r;
}
