//solveur.h list some function useful to solve an equation

# ifndef _EPIQUATION_SOLVEUR_H_
# define _EPIQUATION_SOLVEUR_H_

int has_variable(struct s_tree *tree);

float solveur(struct s_tree *tree);

struct s_tree _solveur(struct s_tree *tree);

void calcul(struct s_tree *node, struct s_tree *value, enum e_operande);

# endif /*_EPIQUATION_SOLVEUR_H_*/
