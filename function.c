# include "function.h"


struct s_function *init_function(enum e_function *func,float para)
{
  struct s_function *fun = malloc(sizeof(struct s_function));
  fun->function = func;
  fun->param = para;
  fun->power = 1;
  fun->mult = 1;
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
  else if (strcmp(function, "tan") == 0)
      *name = TAN;
	else if (strcmp(function, "acos") == 0)
      *name = ACOS;
  else if (strcmp(function, "asin") == 0)
      *name = ASIN;
  else if (strcmp(function, "atan") == 0)
      *name = ATAN;
	else
      *name = UNKNOW_F;
  return name;
}

float calcul_function(struct s_function *function, float val)
{
  float res = 0;
  switch (*function->function)
  {
    case EXP:
      res = expf(val);
      break;
    case LN:
      if (val <= 0)
        set_erreur(5);
      res = logf(val);
      break;
    case COS:
      res = cosf(val);
      break;
		case ACOS:
			res = acosf(val);
			break;
    case SIN:
      res = sinf(val);
      break;
		case ASIN:
			res = asinf(val);
			break;
		case TAN:
			res = tanf(val);
			break;
		case ATAN:
			res = atanf(val);
			break;
    case POW:
      if (function->param == -1 && val == 0)
        set_erreur(4);
      res = powf(val,function->param);
      break;
   	case SQRT:
      if (val <= 0)
        set_erreur(6);
			res = powf(val, 1 / function->param);
			break;
		default:
			set_erreur(7);
			break;
  }
  if(*get_erreur() > 0)
    return 0;
  return calcul(function, res);
}

float calcul_inverse(struct s_function *function, float val)
{
  float res = 0;
  switch (*function->function)
  {
    case LN:
      res = expf(val);
      break;
    case EXP:
      if (val <= 0)
        set_erreur(5);
      res = logf(val);
      break;
    case ACOS:
      res = cosf(val);
      break;
		case COS:
			res = acosf(val);
			break;
    case ASIN:
      res = sinf(val);
      break;
		case SIN:
			res = asinf(val);
			break;
		case ATAN:
			res = tanf(val);
			break;
		case TAN:
			res = atanf(val);
			break;
    case SQRT:
      if (1 / function->param == -1)
        set_erreur(4);
      res = powf(val,1 / function->param);
      break;
   	case POW:
      if (val <= 0)
        set_erreur(6);
			res = powf(val, 1 / function->param);
			break;
		default:
			set_erreur(7);
      break;
  }
  if(*get_erreur() > 0)
    return 0;
  return calcul(function, res);
}

float calcul(struct s_function *function, float val)
{
  return pow(val, 1 / function->power) / function->mult;
}

void free_function(struct s_function *function)
{
  free(function->function);
  free(function);
}
