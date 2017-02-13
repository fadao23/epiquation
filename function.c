# include "function.h"

struct s_function *init_function(enum e_function *func,float *para)
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
  switch (*function)
  {
    case EXP:
      *name = EXP;
      break;
    case LN:
      *name = LN;
      break;
    case SQRT:
      *name = SQRT;
      break;
    case POW:
      *name = POW;
      break;
    case COS:
      *name = COS;
      break;
    case SIN:
      *name = SIN;
      break;
    default:
      *name = UNKNOW;
      break;
  }
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
    case SQRT:
      res = sqrt(val);
      break;
    case COS:
      res = cos(val);
      break;
    case SIN:
      res = sin(val);
      break;
    default:
      res = 0;
      break;
  }
  return pow(res, function->power);
}

void free_function(struct s_function *function)
{
  free(function->function);
  free(function->parameter);
  free(function);
}
