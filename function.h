# ifndef _EPIQUATION_TREE_H_                                                    
# define _EPIQUATION_TREE_H_
/*
 ** enumeration used to list the differents mathematical functions
 */
enum e_function                                                                 
{
  unknow = 0,
  exp,
  ln2,
  sqrt
};


/*                                                                              
 ** struct of function element
 **   function: Identifiant of function
 **   parameter: Optionnal array of parameter usefull for specifique function
 **   power: power of the function
 **   multiplier: multiplier of the function
 */ 
struct s_function
{
  enum e_function *function;
  float           *parameter;
  int             power;
  float           multiplier;
};


/*
 ** Free s_function Struct
 ** Take struct s_function *function in argument
 */
void free_fonction(struct s_function *function);

/* 
  ** Function for make easily s_function
  ** Take all parameters of struct s_function 
*/
struct s_function *creat(enum e_function *func,float *para,int power,
    float multi);

# endif
