# include "function.h"


struct s_function *init_function(enum e_function *func,float para)
{
  struct s_function *fun = malloc(sizeof(struct s_function));
  fun->function = func;
  fun->parameter = para;
  fun->power = 1;
  fun->multiplier = 1;
  return fun;
}

enum e_function *get_function(char *function)
{
  enum e_function *name = malloc(sizeof(enum e_function));
  if ( strcmp(function,"exp") == 0)
      *name = EXP;
  else if (strcmp(function,"ln") == 0)
      *name = LN;
  else if (strcmp(function, "sqrt") == 0)
      *name = SQRT;
  else if (strcmp(function, "pow") == 0)
      *name = POW;
  else if (strcmp(function, "cos") == 0)
      *name = COS;
  else if (strcmp(function, "sin") == 0)
      *name = SIN;
  else
      *name = UNKNOW;
  return name;
}

float calcul_function(struct s_function *function, float val)
{
  float res = 0;
  switch (*function->function)
  {
    case EXP:
      res = exp(val);
      break;
    case LN:
      res = log(val);
      break;
    case SQRT:  //racine n-ieme powf(x, 1/n)
      res = sqrt(val);
      break;
    case COS:
      res = cos(val);
      break;
    case SIN:
      res = sin(val);
      break;
    case POW:
      res = pow(val,function->parameter);
      break;
    default:
      res = 0;
      break;
  }
  return function->multiplier * pow(res, function->power);
}

void free_function(struct s_function *function)
{
  free(function->function);
  free(function);
}
