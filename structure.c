//Data structure for the tree of epiquation

/*
 **	enumeration used for the type of a node
 */
enum e_type
{
  operand,
  function,
  variable,
  value
}

/*
 **	enumeration used to list the differents operands
 */
enum e_operator
{
  plus,
  minus,
  time,
  slash,
  equal
};

/*
 **	enumeration used to list the differents mathematical functions
 */
enum e_function
{
  unknow = 0,
  exp,
  ln2,
  sqrt
};

/*
 **	struct of BTree element
 **		left: the left child
 **		right: the right child
 **		type : the type of the data
 **		data: the data of the node
 */
struct 					s_tree
{
  struct s_tree	*left;
  struct s_tree	*right;
  enum e_type		type
    void					*data;
};

/*
 **	struct of function element
 **		function: Identifiant of function
 **		parameter: Optionnal array of parameter usefull for specifique function
 **		power: power of the function
 **		multiplier: multiplier of the function
 */
struct 							s_function
{
  enum e_function		*function;
  float							*parameter;
  int								power;
  float							multiplier;
};

/*
 **	struct used to store function and data about
 **		name: name of the variable (must be a lowercase letter except for normal number where name is set to 0 or '\0')
 **		power: power of the variable
 **		multiplier:	multiplier of the variable
 */
struct 					s_variable
{
  char 					*name;
  int						power;
  float					multiplier;
};

/*
 **	struct used to store value of variable, this value can be an expression
 **		name: name of the variable
 **		value: value of the variable
 */
struct					s_value
{
  char					*name;
  struct s_tree	*value;
};
