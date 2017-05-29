# include "parsing.h"

struct s_tree *parse(char *equation, int solv)
{
	char 						*rang, *sub_string;
	int 						len;
	struct s_tree 	*tree = NULL;

  set_erreur(0);
	if (solv) {
    rang = strchr(equation, '=');
	  if (rang == NULL)
	    set_erreur(1);
    else if (rang != strrchr(equation, '='))
	    set_erreur(2);
	  else
	  {
      tree = build_operator(*(rang));

      len = rang - equation;
		  sub_string = calloc(len + 1, sizeof (char));
		  strncpy(sub_string, equation, len);
		  tree->left = _parse(sub_string);
		  free(sub_string);

      sub_string = calloc(strlen(equation) - len + 1, sizeof (char));
		  strcpy(sub_string, rang + 1);
      tree->right = _parse(sub_string);
		  free(sub_string);
	  }
	  return tree;
  }
  return _parse(equation);
}

struct s_tree *_parse(char *equation)
{
	char 						*sub_string;
	int 						pos = get_pos_operator(equation);
	struct s_tree 	*tree;
  size_t lgth;
	if (pos != -1)
	{
		tree = build_operator(*(equation + pos));

		sub_string = calloc(pos + 2, sizeof (char));
		if	(pos > 0)
	  {
      strncpy(sub_string, equation, pos);
		  tree->left = _parse(sub_string);
		}
    else
		  tree->left = NULL;
		free(sub_string);

		sub_string = calloc(strlen(equation) - pos, sizeof (char));
		strcpy(sub_string, equation + pos + 1);
		if(*(equation + pos) == '/')
    {
      tree->right = build_function("pow");
      ((struct s_function*) tree->right->data)->param = -1;
      tree->right->left = _parse(sub_string);
    }
    else
      tree->right = _parse(sub_string);
    free(sub_string);
	}
	else if (comp_regex(equation,
  "^[a-z]{2,}\\([0-9a-z\\+\\-\\*/().]+(,[0-9]+)?\\)$"))//Function
	{
    lgth = strcspn(equation, "(");
    sub_string = calloc(lgth + 1, sizeof (char));
    strncpy(sub_string, equation, lgth);
		tree = build_function(sub_string);
    free(sub_string);

    equation += lgth + 1;
    *(equation + strlen(equation) - 1) = '\0';
    lgth = strcspn(equation, ",");
    if(lgth != strlen(equation))
    {
      sub_string = calloc(strlen(equation + lgth + 1) + 1, sizeof (char));
      strcpy(sub_string, equation +lgth + 1);
      sscanf(sub_string, "%f", &((struct s_function*) tree->data)->param);
			free(sub_string);
    }
	  sub_string = calloc(lgth + 1, sizeof (char));
    strncpy(sub_string, equation, lgth);
    tree->left = _parse(sub_string);
    free(sub_string);
  }
	else if (comp_regex(equation, "^\\([0-9a-z,\\+\\-\\*/().]+\\)$"))//parenthesys
	{
		sub_string = calloc(strlen(equation) - 1, sizeof (char));
		strncpy(sub_string, equation + 1, strlen(equation) - 2);
		struct s_tree *tmp = _parse(sub_string);
    free(sub_string);
    return tmp;
	}
	else if (comp_regex(equation, "^[a-z]$"))//variable
	{
		tree = build_variable(equation);
	}
	else if (comp_regex(equation, "^[0-9]+(\\.[0-9]+)?$"))//Number
	{
		tree = build_number(equation);
	}
	else
    set_erreur(3);
  return tree;
}
