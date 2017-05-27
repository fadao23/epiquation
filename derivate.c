

struct s_tree *deriv_var(struct s_tree *node)
{
	new = build_variable(node->data->name);
	new->data->mult = node->data->mult * node->data->power;
	new->data->power = node->data->power - 1;
	return new;
}


struct s_tree *deriv_op(struct s_tree *node)
{
	new = build_operator(node->data->name);
	
	return new;	
}
