# include "tree.h"
# include "build.h"
# include "variable.h"
# include "function.h"
# include "operator.h"

int contain_var (struct s_tree *node);
struct s_tree *deriv (struct s_tree *node);
struct s_tree *deriv_func (struct s_tree *node);
struct s_tree *deriv_var (struct s_tree *node);
struct s_tree *deriv_op (struct s_tree *node);

