# include "test_tree.h"

char *tree_to_string(struct s_tree *tree)
{
  char *rep = calloc(200, sizeof (char));
  _tree_to_string(tree);
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
      _tree_to_string(tree->left);
      operand_to_string(*((enum e_operator*)tree->data));
      _tree_to_string(tree->right);
      if (*((enum e_operator*)tree->data) == PLUS)
        strcat(rep, ")");
      break;
    case FUNCTION:
      function_to_string(*(((struct s_function*)tree->data)->function));
      strcat(rep, "(");
      _tree_to_string(tree->left);
      if(tree->right != NULL)
      {
        strcat(rep, ",");
        _tree_to_string(tree->right);
      }
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
      strcat(rep, "pow");
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
