# include "simplify.h"

/*
	 float simplify_plus(struct s_tree *node, struct s_tree *tmp)
	 {
	 if (node->type == VALUE)
	 return *((float*)node->data);
	 else if (node->type != OPERAND)
	 return 0;
	 else if ( )
	 {
	 simplify_plus()
	 }
	 return res;
	 }
 */

void simplify_minus(struct s_tree *node, int coef)
{
	if (node->type == OPERAND)
	{
		if (*((enum e_operator*) node->data) == MINUS)
		{
			simplify_minus(node->right, coef * (-1));
			*((enum e_operator*) node->data) = PLUS;
		}
		else
		{
			simplify_minus(node->right, coef);
			simplify_minus(node->left, coef);
		}
		else if (node->type == VALUE)
			*((float*) node->data) *= coef;

		else if (node->type == VARIABLE)
			((struct s_variable*) node->data)->mult *= coef;
		else
			((struct s_function*) node->data)->multiplier *= coef;
}



struct s_tree reBuildTree(struct s_list *list, float coef)
{
	if(l->next)
	{
		struct s_tree cur = l.pop();
	}
}



void simplify_mult(struct s_tree *node, struct s_list *list, float coef, int krisbool)
{
	if(!node)
		return;

	if(node->type == OPERAND && *((enum e_operator*) node->data) == MULT)
	{
		if(krisbool == 0)
		{
			list = init_list();
			coef = 1;
		}
		simplify_mult(node->left, list, coef, 1);
		simplify_mult(node->right, list, coef, 1);

		if(krisbool == 1)
		{
				//reBuildTree
		}
	}

	else
	{
		if(krisbool == 1)
			push_list(list, node);

		else
		{
			simplify_mult(node->left, list, coef, 0);
			simplify_mult(node->right, list, coef, 0);
		}
	}
}

