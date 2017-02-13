# include "parsing.h"

struct s_tree *parse(char *equation)
{
	char 						*rang, *sub_string;
	int 						len;
	struct s_tree 	*tree = NULL;

	rang = strchr(equation, '=');
	if (rang == NULL)
		err(1, "No = symbole"); /* ERROR NO =*/
	else if (rang != strrchr(equation, '='))
		err(1, "2 or more symbole equal"); /* ERROR 2 or more = */
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

struct s_tree *_parse(char *equation)
{
	char 						*sub_string;
	int 						pos = get_pos_operator(equation);
	struct s_tree 	*tree;
	if (pos != -1)
	{
		tree = build_operator(*(equation + pos));

		sub_string = calloc(pos + 1, sizeof (char));
		strncpy(sub_string, equation, pos);
		tree->left = _parse(sub_string);
		free(sub_string);

		sub_string = calloc(strlen(equation) - pos, sizeof (char));
		strcpy(sub_string, equation + pos + 1);
		tree->right = _parse(sub_string);
		free(sub_string);
	}
	else if (comp_regex(equation,
  "^[a-z]{2,}\\([0-9a-z\\+-\\*/().]+(,[0-9a-z\\+-\\*/().]+)?\\)$"))//Function
	{
		tree = build_function(equation);
		// build subtree
	}
	else if (comp_regex(equation, "^\\([0-9a-z,\\+-\\*/().]+\\)$"))//parenthesys
	{
		sub_string = calloc(strlen(equation) - 1, sizeof (char));
		strncpy(sub_string, equation + 1, strlen(equation) - 2);
		return _parse(sub_string);
	}
	else if (comp_regex(equation, "^[a-z]$"))//variable
	{
		tree = build_variable(equation);
	}
	else if (comp_regex(equation, "^[0-9]+(\\.[0.9]+)?$"))//Number
	{
		tree = build_number(equation);
	}
	else
		err(1, "Nothing match");
	return tree;
}

char *clean_string(char *string)
{
	int lgt = strlen(string) + 1, cpt = 0, i;
	char *new_s = calloc(lgt, sizeof (char));
	for (i = 0; i < lgt; ++i)
	{
		char c = *(string + i);
		if (c >= 'A' && c <= 'Z')
			*(new_s + cpt++) = c + 32;
		else if ((c >= '(' && c <= '9') || (c >= 'a' && c <= 'z') || c == '=')
			*(new_s + cpt++) = c;
	}
	return realloc(new_s, cpt * sizeof (char));
}

int comp_regex(char *string, char *reg)
{
 	regex_t regex;
	int 		err_reg = 0;
	err_reg = regcomp(&regex, reg, REG_NOSUB | REG_EXTENDED | REG_NEWLINE);
	if (err_reg)
  {
  err(1, "Error initialising function regex");
	}
  err_reg = regexec(&regex, string, 0, NULL, 0);
	if (!err_reg)
		return 1;
	else if (err_reg == REG_NOMATCH)
		return 0;
	else
		err(1, "Error executing function regex");
}

struct s_tree *build_operator(char oper)
{
	struct s_tree *node = malloc(sizeof (struct s_tree));
	node->type = OPERAND;
	node->data = get_operator(oper);
	return node;
}

struct s_tree *build_function(char *func)
{
  (void)func;
	struct s_tree *node = malloc(sizeof (struct s_tree));
	node->type = FUNCTION;
  //FIX IT
	return NULL;
}

struct s_tree *build_variable(char *var)
{
	struct s_tree *node = malloc(sizeof (struct s_tree));
	node->type = VARIABLE;
	node->data = init_variable(*var);
  return node;
}

struct s_tree *build_number(char *number)
{
	struct s_tree *node = malloc(sizeof (struct s_tree));
	float *res = malloc(sizeof (float));
	sscanf(number, "%f", res);
	node->type = VALUE;
	node->data = res;
	return node;
}
