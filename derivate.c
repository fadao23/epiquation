int contain_var (struct s_tree *node)
{
  if (node)
		return 0;
	if (node->type != VARIABLE)
		return contain_var(node->left) || contain_var(node->right);
	return 1;
}


struct s_tree *deriv (struct s_tree *node)
{
	if (node->type == VARIABLE)
		return deriv_var(node);
  if (node->type == OPERAND)
    return deriv_op(node);
  if (node->type == FUNCTION)
    return deriv_func(node);
	return NULL;
}

struct s_tree *deriv_func (struct s_tree *node)
{
  if (node->data->function == EXP)
	{
	  return deriv_exp(node);
  }
	if (node->data->funcction == LN)
	{
		new = build_operator("*");
    new->left = deriv(node->left);
		new->right = build_function("pow");
    new->right-> = node->data->param; // ?
		new->right->power = -1;
	}
	if (node->data->funcction == SQRT || POW)
	{
		new = build_operator("*");
		new->left = deriv(node->data->param)
	}
}


struct s_tree *deriv_var (struct s_tree *node)
{
	struct s_tree *new = build_variable(node->data->name);
	((struct s_var*)new->data)->mult 
    = ((struct s_var*) node->data)->mult * ((struct s_var*)node->data)->power;
	((struct s_var*)new->data)->power = ((struct s_var*) node->data)->power - 1;
	return new;
}


struct s_tree *deriv_op (struct s_tree *node)
{
	struct s_tree *new;
	if (*(node->data) == TIME)
	{
		new = build_operator("+");
		new->left = build_operator("*");
		new->left->left = deriv(node->left);
		new->left->right = node->right;
	
		new->right = build_operator("*");
		new->right->left = deriv(node->right);
    new->right->right = node->left;
	}
	else
	{
		struct s_tree *left, *right;
		if (contain_var(node->left))
			left = deriv(node->left);
		if (contain_var(node->right))
			right = deriv(node->right);
		if (left && right) {
			new = build_operator('+');
			new->left = left;
			new->right = right;
		}
		else
			new = (right)? right : left;
	}
	return new;
}
