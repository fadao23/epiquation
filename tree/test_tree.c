# include "test_tree.h"

char *tree_to_string(struct s_tree *tree)
{
  char *rep = calloc(200, sizeof (char));
  _tree_to_string(tree, rep);
  return rep;
}

void _tree_to_string(struct s_tree *tree, char *rep)
{
  if(!tree)
    return;
  switch (tree->type)
  {
    case OPERAND:
      if (*((enum e_operator*)tree->data) == PLUS)
        strcat(rep, "(");
      _tree_to_string(tree->left, rep);
      operand_to_string(*((enum e_operator*)tree->data), rep);
      _tree_to_string(tree->right, rep);
      if (*((enum e_operator*)tree->data) == PLUS)
        strcat(rep, ")");
      break;
    case FUNCTION:
      function_to_string(*(((struct s_function*)tree->data)->function), rep);
      strcat(rep, "(");
      _tree_to_string(tree->left, rep);
      if(*(((struct s_function*)tree->data)->function) == POW)
      {
        sprintf(rep, "%s)^%03.2f", rep, ((struct s_function*)tree->data)->param);
      }
      else
        strcat(rep, ")");
      break;
    case VARIABLE:
      sprintf(rep, "%s%.1f%c",rep, ((struct s_variable*)tree->data)->mult,
          ((struct s_variable*)tree->data)->name);
      if (((struct s_variable*)tree->data)->power != 1)
        sprintf(rep, "%s^%d", rep, ((struct s_variable*)tree->data)->power);
      break;
    case VALUE:
      sprintf(rep, "%s%03.2f",rep, *((float*)tree->data));
      break;
  }
}

void function_to_string(enum e_function function, char *rep)
{
  switch (function)
  {
    case EXP:
      strcat(rep, "exp");
      break;
    case LN:
      strcat(rep, "ln");
      break;
    case SQRT:
      strcat(rep, "sqrt");
      break;
    case POW:
      break;
    case COS:
      strcat(rep, "cos");
      break;
    case SIN:
      strcat(rep, "sin");
      break;
    default:
      strcat(rep, "Unknown");
      break;
  }
}

void operand_to_string(enum e_operator operand, char *rep)
{
  switch (operand)
  {
    case PLUS:
      strcat(rep, "+");
      break;
    case MINUS:
      strcat(rep, "-");
      break;
    case TIME:
      strcat(rep, "*");
      break;
    case EQUAL:
      strcat(rep, "=");
      break;
    default:
      printf("   ERROR   ");
      break;
  }
}
