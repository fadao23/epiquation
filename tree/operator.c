# include "operator.h"

int get_pos_operator(char *equation)
{
  int pile = 0, len = strlen(equation), pos = -1, i;
	enum e_operator op = UNKNOW;
  char c;
  for (i = 0; i < len; ++i)
  {
    c = *(equation + i);
    if (c == '(')
      pile++;
    else if (c == ')')
      pile--;
    else if (c == '+' && pile == 0 && PLUS >= op)
    {
      op = PLUS;
      pos = i;
    }
    else if (c == '-' && pile == 0 && MINUS >= op)
    {
      op = MINUS;
      pos = i;
    }
    else if ((c == '/' || c == '*') && pile == 0 && TIME >= op)
    {
      op = TIME;
      pos = i;
    }
  }
  return pos;
}

enum e_operator *get_operator(int num_operator)
{
	enum e_operator *op = malloc(sizeof (enum e_operator));
  switch(num_operator)
  {
    case '+':
      *op = PLUS;
      break;
    case '-':
      *op = MINUS;
      break;
    case '*':
      *op = TIME;
      break;
    case '=':
      *op = EQUAL;
      break;
    default:
      *op = UNKNOW;
      break;
  }
	return op;
}
