# include "test_tree.h"

void tree_to_string(struct s_tree *tree)
{
  _tree_to_string(tree);
  printf("\n");
}

void _tree_to_string(struct s_tree *tree)
{
  switch (tree->type)
  {
    case OPERAND:
      printf("(");
      _tree_to_string(tree->left);
      operand_to_string(*((char*)tree->data));
      _tree_to_string(tree->right);
      printf(")");
      break;
    case FUNCTION:
      function_to_string(*(((struct s_function*)tree->data)->function));
      printf("(");
      _tree_to_string(tree->left);
      if(tree->right != NULL)
      {
        printf(",");
        _tree_to_string(tree->right);
      }
      printf(")");
      break;
    case VARIABLE:
      printf("%c", ((struct s_variable*)tree->data)->name);
      break;
    case VALUE:
      printf("%03.2f", *((float*)tree->data));
      break;
  }
}

void function_to_string(enum e_function function)
{
  switch (function)
  {
    case EXP:
      printf("exp");
      break;
    case LN:
      printf("ln");
      break;
    case SQRT:
      printf("sqrt");
      break;
    case POW:
      printf("pow");
      break;
    case COS:
      printf("cos");
      break;
    case SIN:
      printf("sin");
      break;
  }
}

void operand_to_string(enum e_operator operand)
{
  switch (operand)
  {
    case PLUS:
      printf("+");
      break;
    case MINUS:
      printf("-");
      break;
    case TIME:
      printf("*");
      break;
    case SLASH:
      printf("/");
      break;
    case EQUAL:
      printf("=");
      break;
    default:
      printf("   ERROR   ");
      break;
  }
}
